// TASKING VX-toolset for TriCore
// Eclipse project linker script file
//
#define INTTAB 0x80074000
#if defined(__PROC_TC23X__)
#define __BMHD0_CONFIG __BMHD_GENERATE
#include "tc23x.lsl"
derivative my_tc23x extends tc23x
{
}
#else
#include <cpu.lsl>
#endif
