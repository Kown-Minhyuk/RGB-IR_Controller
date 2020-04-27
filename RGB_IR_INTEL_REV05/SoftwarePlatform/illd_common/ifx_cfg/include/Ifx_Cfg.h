/*
 * Ifx_Cfg.h
 *
 *  Created on: May 6, 2015
 *      Author: gerhard.mennen
 */

#ifndef IFX_CFG_H
#define IFX_CFG_H

#include <aurix_illd_cfg.h>

#if (AURIX_ILLD_IFX_ASSERT != 0)
#include <stdio.h>	/* for printf used in IFX_ASSERT below */
#endif


// XTAL/PLL frequency
#define IFX_CFG_SCU_XTAL_FREQUENCY    (AURIX_ILLD_XTAL_FREQ)
#define IFX_CFG_SCU_PLL_FREQUENCY    (AURIX_ILLD_PLL_FREQ)


#ifdef  __cplusplus
extern "C" {
#endif

// Assertions
#if (AURIX_ILLD_IFX_ASSERT != 0)
extern const char* verboseLevelStr[6];
#  define IFX_ASSERT(level, expr) (((expr) || (level > IFX_VERBOSE_LEVEL_ERROR)) ? ((void)0) : (void)printf("[ASSERT:%s] '%s' in %s:%d (function '%s')\n", verboseLevelStr[level], #expr, __FILE__, __LINE__, __func__))
#else
#  define IFX_ASSERT(level, expr)
#endif

#if (AURIX_ILLD_IFX_USE_SW_MANAGED_INT != 0)
# define IFX_USE_SW_MANAGED_INT
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_CFG_H */
