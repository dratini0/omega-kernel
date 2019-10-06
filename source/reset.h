#ifndef RESET_HEADER
#define RESET_HEADER

#include <gba_base.h>
#include <gba_systemcalls.h>

void SoftReset_now_iwram(void);
void SoftReset_iwram(RESTART_FLAG RestartFlag);
void HardReset_iwram(void);
void RegisterRamReset_iwram(int ResetFlags);

#endif
