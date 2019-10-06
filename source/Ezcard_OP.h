#include <gba_base.h>

#include "ff.h"

void IWRAM_CODE SD_Enable(void);
void IWRAM_CODE SD_Disable(void);
u32 IWRAM_CODE Read_SD_sectors(u32 address,u16 count,u8* SDbuffer);
u32 IWRAM_CODE Write_SD_sectors(u32 address,u16 count,const u8* SDbuffer);
u16 IWRAM_CODE Read_S71NOR_ID();
u16 IWRAM_CODE Read_S98NOR_ID();
void IWRAM_CODE SetRompage(u16 page);
void IWRAM_CODE SetPSRampage(u16 page);
void IWRAM_CODE SetRampage(u16 page);
void IWRAM_CODE Send_FATbuffer(u32*buffer,u32 mode);
void IWRAM_CODE SetRompageWithHardReset(u16 page,u32 bootmode);
void IWRAM_CODE ReadSram(u32 address, u8* data , u32 size );
void IWRAM_CODE WriteSram(u32 address, u8* data , u32 size );
void IWRAM_CODE Bank_Switching(u8 bank);
void IWRAM_CODE Save_NOR_info(u8 * NOR_info_buffer,u32 buffersize);
void IWRAM_CODE Save_SET_info(u16 * SET_info_buffer,u32 buffersize);
void IWRAM_CODE Read_NOR_info();
u16 IWRAM_CODE Read_SET_info(u32 offset);
void IWRAM_CODE SPI_Enable(void);
void IWRAM_CODE SPI_Disable(void);
u16 IWRAM_CODE Read_FPGA_ver(void);
void IWRAM_CODE Set_RTC_status(u16  status);
void IWRAM_CODE Set_AUTO_save(u16  mode);
void IWRAM_CODE Check_FW_update(u16 Current_FW_ver,u16 Built_in_ver);
