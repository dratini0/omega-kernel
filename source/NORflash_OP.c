#include <gba_interrupt.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include <gba_base.h>
#include <gba_dma.h>
#include <string.h>
#include <gba_systemcalls.h>

#include "NORflash_OP.h"
#include "ezkernel.h"
#include "draw.h"
#include "lang.h"
#include "Ezcard_OP.h"
#include "GBApatch.h"
#include "MENU.h"
#define DEBUG

//---------------------------------------------------------------
void Chip_Reset()
{
	FlashBase_S98[0] = 0xF0;
}
//---------------------------------------------------------------
void Block_Erase(u32 blockAdd) //0x20000 BYTE pre block
{
	vu16 page,v1,v2;
	u32 Address;
	u32 loop;

	page=gl_currentpage;
	Address=blockAdd;
	while(Address>=0x800000)
	{
		Address-=0x800000;
		page+=0x1000;
	}
	SetRompage(page);
	Chip_Reset();
	v1=0;v2=1;
	if((blockAdd==0) || (blockAdd==0x3FE0000))
	{
		for(loop=0;loop<0x20000;loop+=0x8000)
		{
			FlashBase_S98[0x555] = 0xAA ;
			FlashBase_S98[0x2AA] = 0x55 ;
			FlashBase_S98[0x555] = 0x80 ;
			FlashBase_S98[0x555] = 0xAA ;
			FlashBase_S98[0x2AA] = 0x55 ;
			FlashBase_S98[(Address + loop)/2] = 0x30 ;
			do
			{
				v1 = FlashBase_S98[(Address + loop)/2];
				v2 = FlashBase_S98[(Address + loop)/2];
			}while(v1!=v2);
		}
	}
	else
	{
		loop=Address;

		FlashBase_S98[0x555] = 0xAA ;
		FlashBase_S98[0x2AA] = 0x55 ;
		FlashBase_S98[0x555] = 0x80 ;
		FlashBase_S98[0x555] = 0xAA ;
		FlashBase_S98[0x2AA] = 0x55 ;
		FlashBase_S98[loop/2] = 0x30 ;
		do
		{
			v1 = FlashBase_S98[loop/2] ;
			v2 = FlashBase_S98[loop/2] ;
		}while(v1!=v2);
	}
	SetRompage(gl_currentpage);
}
//-----------------------------------------------------------
void Chip_Erase()
{
	char msg[128];
	u32 count=0;
	vu16 v1,v2=0 ;
	REG_IME = 0 ;
	FlashBase_S98[0x555] = 0xAA ;
	FlashBase_S98[0x2AA] = 0x55 ;
	FlashBase_S98[0x555] = 0x80 ;
	FlashBase_S98[0x555] = 0xAA ;
	FlashBase_S98[0x2AA] = 0x55 ;
	FlashBase_S98[0x555] = 0x10 ;
	do
	{
		VBlankIntrWait();		
		VBlankIntrWait();	
		ShowTime(NOR_list,0);
		DrawPic((u16*)MENUBitmap + 78*128, 56, 90+13, 128, 13, 0, 0, 1);//show menu pic
		
		itoa(count,msg,2);
		DrawHZText12(msg,0,60,90+13,gl_color_text,1);
		count++;

		VBlankIntrWait();
		v1 = FlashBase_S98[0];
		v2 = FlashBase_S98[0];
	}while(v1!=v2);
	REG_IME = 1 ;
}

//-----------------------------------------------------------
void FormatNor()
{
	char msg[128];
	sprintf(msg,"%s",gl_formatnor_info);

	DrawHZText12(msg,0,60,90,gl_color_text,1);

	while(1)
	{
		delay(500);
		scanKeys();
		u16 keys = keysDown();
		if (keys & KEY_A) {
			Chip_Erase();
			memset(pNorFS,00,sizeof(FM_NOR_FS)*MAX_NOR);
			return;
		}
		else if(keys & KEY_B) {
			return;
		}
	}
}
//---------------------------------------------------------------
void WriteFlash(u32 address,u8 *buffer,u32 size)
{
	vu16 page,v1,v2;
	register u32 loopwrite ;
	vu16* buf = (vu16*)buffer ;

	page=gl_currentpage;
	while(address>=0x800000)
	{
		address-=0x800000;
		page+=0x1000;
	}
	SetRompage(page);

	Chip_Reset();
	v1=0;v2=1;
	for(loopwrite=0;loopwrite<(size/2);loopwrite++)
	{
		FlashBase_S98[0x555] = 0xAA ;
		FlashBase_S98[0x2AA] = 0x55 ;
		FlashBase_S98[0x555] = 0xA0 ;
		FlashBase_S98[address/2 + loopwrite] = buf[loopwrite];
		do
		{
			v1 = FlashBase_S98[address/2 + loopwrite] ;
			v2 = FlashBase_S98[address/2 + loopwrite] ;
		}while(v1!=v2);
	}
	SetRompage(gl_currentpage);
}
//---------------------------------------------------------------
void WriteFlash_with32word(u32 address,u8 *buffer,u32 size)
{
	vu16 page,v1,v2;
	register u32 loopwrite ;
	vu16* buf = (vu16*)buffer ;
	u32 i;

	page=gl_currentpage;
	while(address>=0x800000)
	{
		address-=0x800000;
		page+=0x1000;
	}
	SetRompage(page);

	Chip_Reset();
	v1=0;v2=1;
	for(loopwrite=0;loopwrite<(size/32);loopwrite++)
	{
		FlashBase_S98[0x555] = 0xAA ;
		FlashBase_S98[0x2AA] = 0x55 ;
		FlashBase_S98[address/2 + loopwrite*16] = 0x25;
		FlashBase_S98[address/2 + loopwrite*16] = 15;
		for(i=0;i<=15;i++)
		{
			FlashBase_S98[address/2 + loopwrite*16 + i] = buf[loopwrite*16 + i];
		}	
		FlashBase_S98[address/2 + loopwrite*16] = 0x29;
		
		do
		{
			v1 = FlashBase_S98[address/2 + loopwrite*16 + 0xF];
			v2 = FlashBase_S98[address/2 + loopwrite*16 + 0xF];
		}while(v1!=v2);
	}
	SetRompage(gl_currentpage);
}
//-----------------------------------------------------------
u32 Loadfile2NOR(TCHAR *filename, u32 NORaddress,u32 have_patch)
{
	u32 res;
	UINT ret;
	u32 filesize;
	u32 fileneedsize;
	
	u32 blocknum;
	char msg[128];	
	FM_NOR_FS tmpNorFS ;
	char temp[50];

	u32 add_patch = 0;
			
	u16 norid = Read_S98NOR_ID();
	if(norid == 0x223D)//S98
	{
		res = f_open(&gfile, filename, FA_READ);
		if(res != FR_OK)
				return 0;
		
		filesize = f_size(&gfile);		
		f_lseek(&gfile, 0xa0);		
		f_read(&gfile, temp, 0x10, &ret);//read game name

		memcpy(tmpNorFS.gamename,temp,0x10);
		tmpNorFS.rompage = NORaddress >> 17;
		
		fileneedsize = ((((filesize+0x1FFFF)/0x20000)*0x20000));
		if(have_patch)
		{			
			if(iTrimSize>=fileneedsize)
			{
				fileneedsize = fileneedsize+0x20000;
				add_patch = 1;
			}
		}
			
		if(	fileneedsize > (0x4000000-NORaddress)){
			return 2; //Not enough NOR space 
		}

		
		////////////////// erase all BBP
		FlashBase_S98[0] = 0xF0 ;	
		
		FlashBase_S98[0x555] = 0xAA ;
		FlashBase_S98[0x2AA] = 0x55 ;
		FlashBase_S98[0x555] = 0xC0 ;		
		FlashBase_S98[0x000] = 0x80 ;
		FlashBase_S98[0x000] = 0x30 ;
		{
			int polling_counter = 0x15000;
			u32 v1;
			do {
				v1 = FlashBase_S98[0x2E0000];
				polling_counter--;

			} while (polling_counter);
		}	
		FlashBase_S98[0] = 0x90 ;
		FlashBase_S98[0] = 0x00 ;			
		/////////////////		
		
			
		tmpNorFS.filesize = fileneedsize;
		tmpNorFS.have_patch = have_patch;
		tmpNorFS.have_RTS = gl_rts_on;
		
		sprintf(tmpNorFS.filename,"%s",filename);
		dmaCopy(&tmpNorFS,&pNorFS[game_total_NOR], sizeof(FM_NOR_FS));
 
		Clear(60,160-15,120,15,gl_color_cheat_black,1);	
		DrawHZText12(gl_writing,0,78,160-15,gl_color_text,1);	
		for(blocknum=0;blocknum<filesize;blocknum+=0x20000)
		{		
			sprintf(msg,"%luMb",(blocknum)/0x20000);
			Clear(78+54,160-15,100,15,gl_color_cheat_black,1);
			DrawHZText12(msg,0,78+54,160-15,gl_color_text,1);
			Block_Erase(blocknum+NORaddress);

			f_lseek(&gfile, blocknum);
			f_read(&gfile, pReadCache, 0x20000, &ret);//pReadCache max 0x20000 Byte
			if(have_patch){
				if((gl_reset_on==1) || (gl_rts_on==1) || (gl_sleep_on==1) || (gl_cheat_on==1))		    
				{
					PatchInternal((u32*)pReadCache,0x20000,blocknum);	
					GBApatch_NOR((u32*)pReadCache,0x20000,blocknum);//some nes need check				
				}
			}
			else{
				GBApatch_Cleanrom_NOR((u32*)pReadCache,blocknum);
			}
				
			WriteFlash_with32word(blocknum+NORaddress,pReadCache,0x20000);

		}
		f_close(&gfile);
		
		if(have_patch)
		{
			if(add_patch)
			{
				Block_Erase(blocknum+NORaddress);
				GBApatch_NOR((u32*)pReadCache,0x20000,blocknum);
				WriteFlash_with32word(blocknum+NORaddress,pReadCache,0x20000);
			}
		}
		
		Save_NOR_info((u8 *) pNorFS,sizeof(FM_NOR_FS)*0x40);
		return 0;
	}		
	else
	{
		#ifdef DEBUG
			DEBUG_printf("Bad NOR ID");
		#endif
		return 1;
	}
}
//-----------------------------------------------------------
u32 GetFileListFromNor(void)
{
	REG_IME = 0 ;
	u32 page=0 ,count=0;
	vu8 *StartAddress = (vu8 *) FlashBase_S98;
	char temp[50];
	vu16  Value;

	Value = *(vu16 *)(StartAddress + 0xbe);
	u16 x24 = *(vu16 *)(StartAddress + 0x6);

	DEBUG_printf(" %x %x %x",StartAddress,Value,x24);

	while( ((Value&0xFF)==0xCE) || ((Value&0xFF)==0xCF)|| ((Value&0xFF)==0x00)|| (x24==0x51ae))
	{
		DEBUG_printf(" %x %x %x",StartAddress,Value,x24);
		if(*(vu8 *)(StartAddress+0xb2) == 0x96)
		{
			memcpy(temp,(char*)(StartAddress+0xa0),0x10);

			DEBUG_printf("  %s VS %s",temp ,pNorFS[count].gamename);
			
			if(memcmp(temp,pNorFS[count].gamename,0x10) ==0)
			{
				gl_norOffset += pNorFS[count].filesize;
				StartAddress += pNorFS[count].filesize;
				count ++ ;
			}
			else 
			{
				break;
			}
		}
		else
		{
			break;
		}		

		while(StartAddress >= (vu8 *) FlashBase_S98_end)
		{
			page += 0x1000 ;
			if(page>0x7000)
			{
				SetRompage(gl_currentpage);
				return count;
			}
			SetRompage(gl_currentpage+page);
			StartAddress -= 0x800000 ;
		}
		if(count > MAX_NOR) 
			break; //max
			
		Value = *(vu16 *)(StartAddress + 0xbe);
		x24 = *(vu16 *)(StartAddress + 0x6);
	}
	SetRompage(gl_currentpage);

	REG_IME   = 1 ;
	return count ;
}
//-----------------------------------------------------------
