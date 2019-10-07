#ifndef SETWINDOW_HEADER
#define SETWINDOW_HEADER

#include <gba_base.h>

extern u16 SET_info_buffer [0x200]EWRAM_BSS;

u32 Setting_window(void);
void Draw_select_icon(u32 X,u32 Y,u32 mode);

#endif
