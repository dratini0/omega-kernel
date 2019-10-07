#ifndef DRAW_HEADER
#define DRAW_HEADER

#include <gba_base.h>

#ifdef DEBUG
void DEBUG_printf(const char *format, ...);
#else
#define DEBUG_printf(...) {}
#endif

void IWRAM_CODE Clear(u16 x, u16 y, u16 w, u16 h, u16 c, u8 isDrawDirect);
void IWRAM_CODE ClearWithBG(u16* pbg,u16 x, u16 y, u16 w, u16 h, u8 isDrawDirect);
void IWRAM_CODE DrawPic(u16 *GFX, u16 x, u16 y, u16 w, u16 h, u8 isTrans, u16 tcolor, u8 isDrawDirect);
void DrawHZText12(const char *str, u16 len, u16 x, u16 y, u16 c, u8 isDrawDirect);
void ShowbootProgress(const char *str);

#endif
