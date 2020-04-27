/* Include Header files */
#include "IfxScuCcu_ActInit.h"
#include "IfxScu_cfg_instance.h"

/*------------------------------------------*/
/*                File Extensions           */
/*------------------------------------------*/
static const IfxScuCcu_PllStepsConfig IfxScuCcu_testPllConfigSteps[] = {
IFXSCU_CFG_PLL_STEPS
};

IfxScuCcu_Config                      IfxScuCcu_testClockConfig = {
    {
        sizeof(IfxScuCcu_testPllConfigSteps) / sizeof(IfxScuCcu_PllStepsConfig),
(IfxScuCcu_PllStepsConfig *)IfxScuCcu_testPllConfigSteps,
        IFXSCU_CFG_PLL_INITIAL_STEP,
    },
    IFXSCU_CFG_CLK_DISTRIBUTION,
    IFXSCU_CFG_FLASH_WAITSTATE,
    IFX_CFG_SCU_XTAL_FREQUENCY
};


/*-------------------------------------------------------------*/
/*                Generation of ACT Interrupts...              */
/*-------------------------------------------------------------*/




/**
 * @brief
 *      Initialize IfxScuCcu driver
 *
 * This function initializes the SCU CCU.
 *
 * @return  none
 */

extern void IfxScuCcu_ActInit(void) {
	IfxScuCcu_init(&IfxScuCcu_testClockConfig);
}

