/**
 *                                IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 */

/*-------------------------------------------------*/
/*                Include Header Files             */
/*-------------------------------------------------*/
#include "IfxStm_ActInit.h"
#include "IfxStm_cfg_instance.h"

#include <Cpu/Irq/IfxCpu_Irq.h>

/*-------------------------------------------------------------*/
/*                 Interrupts                                  */
/*-------------------------------------------------------------*/


#if IFXSTM_INSTANCE_MODULE_STM0_USED == 1
IFX_INTERRUPT(stm0Int0Handler, IFX_STM0_IFXSTM_INSTANCE_COMPARECONFIG0_TYPEOFSERVICE, IFX_STM0_IFXSTM_INSTANCE_COMPARECONFIG0_TRIGGERPRIORITY );

#if IFX_STM0_IFXSTM_INSTANCE_NUMCOMPARATORS == 2
IFX_INTERRUPT(stm0Int1Handler, IFX_STM0_IFXSTM_INSTANCE_COMPARECONFIG1_TYPEOFSERVICE, IFX_STM0_IFXSTM_INSTANCE_COMPARECONFIG1_TRIGGERPRIORITY);
#endif

#endif

#if IFXSTM_INSTANCE_MODULE_STM1_USED == 1
IFX_INTERRUPT(stm1Int0Handler, IFX_STM1_IFXSTM_INSTANCE_COMPARECONFIG0_TYPEOFSERVICE, IFX_STM1_IFXSTM_INSTANCE_COMPARECONFIG0_TRIGGERPRIORITY );

#if IFX_STM1_IFXSTM_INSTANCE_NUMCOMPARATORS == 2
IFX_INTERRUPT(stm1Int1Handler, IFX_STM1_IFXSTM_INSTANCE_COMPARECONFIG1_TYPEOFSERVICE, IFX_STM1_IFXSTM_INSTANCE_COMPARECONFIG1_TRIGGERPRIORITY);
#endif

#endif

#if IFXSTM_INSTANCE_MODULE_STM2_USED == 1
IFX_INTERRUPT(stm2Int0Handler, IFX_STM2_IFXSTM_INSTANCE_COMPARECONFIG0_TYPEOFSERVICE, IFX_STM2_IFXSTM_INSTANCE_COMPARECONFIG0_TRIGGERPRIORITY );

#if IFX_STM2_IFXSTM_INSTANCE_NUMCOMPARATORS == 2
IFX_INTERRUPT(stm2Int1Handler, IFX_STM2_IFXSTM_INSTANCE_COMPARECONFIG1_TYPEOFSERVICE, IFX_STM2_IFXSTM_INSTANCE_COMPARECONFIG1_TRIGGERPRIORITY);
#endif

#endif


#if IFXSTM_INSTANCE_MODULE_STM0_USED == 1

void stm0Int0Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM0];

    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig0.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig0.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}
#if IFX_STM0_IFXSTM_INSTANCE_NUMCOMPARATORS == 2 
void stm0Int1Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM0];

    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig1.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig1.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}
#endif
#endif

#if IFXSTM_INSTANCE_MODULE_STM1_USED == 1

void stm1Int0Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM1];
    
    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig0.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig0.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}
#if IFX_STM1_IFXSTM_INSTANCE_NUMCOMPARATORS == 2
void stm1Int1Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM1];
    
    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig1.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig1.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}
#endif
#endif

#if IFXSTM_INSTANCE_MODULE_STM2_USED == 1

void stm2Int0Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM2];
    
    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig0.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig0.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}

#if IFX_STM2_IFXSTM_INSTANCE_NUMCOMPARATORS == 2
void stm2Int1Handler(void)
{
    const IfxStm_cfg_instance_t *instance = &IfxStm_instance_table[IFX_STM2];
    
    IfxStm_clearCompareFlag(instance->Module, instance->CompareConfig1.comparator);
    IfxStm_updateCompare(instance->Module, instance->CompareConfig1.comparator, IfxStm_getLower(instance->Module) + 1000);
    IfxCpu_enableInterrupts();
}
#endif
#endif


#if defined(IFX_USE_SW_MANAGED_INT)
void IfxStm_ActRegisterInterrupt(unsigned int id)
{
    #if IFXSTM_INSTANCE_MODULE_STM0_USED == 1
    if (IfxStm_instance_table[id].Module == IFXSTM_INSTANCE_MODULE_STM0)
    {
        IfxCpu_Irq_installInterruptHandler(stm0Int0Handler, IfxStm_instance_table[id].CompareConfig0.triggerPriority);
        #if IFX_STM0_IFXSTM_INSTANCE_NUMCOMPARATORS == 2 
        IfxCpu_Irq_installInterruptHandler(stm0Int1Handler, IfxStm_instance_table[id].CompareConfig1.triggerPriority);
        #endif
    }
    #endif

    #if IFXSTM_INSTANCE_MODULE_STM1_USED == 1
    if (IfxStm_instance_table[id].Module == IFXSTM_INSTANCE_MODULE_STM1)
    {
        IfxCpu_Irq_installInterruptHandler(stm1Int0Handler, IfxStm_instance_table[id].CompareConfig0.triggerPriority);
        #if IFX_STM1_IFXSTM_INSTANCE_NUMCOMPARATORS == 2 
        IfxCpu_Irq_installInterruptHandler(stm1Int1Handler, IfxStm_instance_table[id].CompareConfig1.triggerPriority);
        #endif
    }
    #endif

    #if IFXSTM_INSTANCE_MODULE_STM2_USED == 1
    if (IfxStm_instance_table[id].Module == IFXSTM_INSTANCE_MODULE_STM2)
    {
        IfxCpu_Irq_installInterruptHandler(stm2Int0Handler, IfxStm_instance_table[id].CompareConfig0.triggerPriority);
        #if IFX_STM2_IFXSTM_INSTANCE_NUMCOMPARATORS == 2 
        IfxCpu_Irq_installInterruptHandler(stm2Int1Handler, IfxStm_instance_table[id].CompareConfig1.triggerPriority);
        #endif
    }
    #endif
}
#endif



/*-------------------------------------------------*/
/*                Functions                         */
/*-------------------------------------------------*/

/** \brief Initialize IfxStm driver
 * This function initializes the STM driver identified by @em id 
 * \param id Valid driver id (see devices.h from SoftwarePlatform/Configuration).  
 * \return pointer for use STM Driver.  
 */
extern Ifx_STM* IfxStm_ActInit(uint32 id)
{
    assert(id < IFXSTM_INSTANCE_COUNT);

#if defined(IFX_USE_SW_MANAGED_INT)
    IfxStm_ActRegisterInterrupt(id);
#endif

    /* module initialization */
    IfxStm_initCompare(IfxStm_instance_table[id].Module, &IfxStm_instance_table[id].CompareConfig0);
    if(IfxStm_instance_table[id].numComparators == 2)
    {
        IfxStm_initCompare(IfxStm_instance_table[id].Module,  &IfxStm_instance_table[id].CompareConfig1);
    }    

    return IfxStm_instance_table[id].Module;
}


