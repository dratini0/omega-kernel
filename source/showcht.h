#ifndef SHOWCHT_HEADER
#define SHOWCHT_HEADER

#include <gba_base.h>


#define MAX_BUF_LEN 6000
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 6000

#define MAX_sectionVAL_LEN 300
#define MAX_CHEAT_COUNT 3000

typedef struct CHT_LINE{
	char LINEname[MAX_KEY_LEN];
	//char KEY_val[256];
	u8 is_section ;
	u8 section_val_count ;
	u8 len;
	u8 select ;
} FM_CHT_LINE;

typedef struct ST_entry_{	
	u32  address;		
	u32  VAL;	
} ST_entry;

extern ST_entry pCHEAT[MAX_CHEAT_COUNT];
extern u32 gl_cheat_count;

//int Get_KEY_val(FIL* file,char*KEY_section,char*KEY_secval,char getbuff[]);
u32 Check_cht_file(TCHAR *gamefilename);
void Open_cht_file(TCHAR *gamefilename,u32 havecht);
void Trim(char s[]);

#endif
