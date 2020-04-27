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


#ifndef __IFXSTM_ACTINIT_H_
#define __IFXSTM_ACTINIT_H_

/*-------------------------------------------------*/
/*                Include Header Files             */
/*-------------------------------------------------*/

#include <Stm/Std/IfxStm.h>
#include <PinMapper/aurix_pin_mappings.h>
#include <devices.h>
#include <IfxStm_cfg_instance.h>
#include <stddef.h>
#include <assert.h>

/*-------------------------------------------------*/
/*                Function Prototypes               */
/*-------------------------------------------------*/
/** \brief Initialize IfxStm driver
 * This function initializes the STM driver identified by @em id 
 * \param id Valid driver id (see devices.h from SoftwarePlatform/Configuration).  
 * \return pointer for use STM Driver.  
 */
extern Ifx_STM* IfxStm_ActInit(uint32 id);


#endif

