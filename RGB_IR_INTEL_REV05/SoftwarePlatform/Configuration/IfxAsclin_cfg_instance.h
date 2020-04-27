/*
 *  Software Platform Generated File
 *  --------------------------------
 */

#ifndef _SWP_IFXASCLIN_CFG_INSTANCE_H
#define _SWP_IFXASCLIN_CFG_INSTANCE_H

#include "IfxAsclin_cfg.h"


#define IFXASCLIN_INSTANCE_MODULE_ASCLIN0  &MODULE_ASCLIN0
#define IFXASCLIN_INSTANCE_MODULE_ASCLIN1  &MODULE_ASCLIN1

#define IFXASCLIN_INSTANCE_MODULE_ASCLIN0_USED  0
#define IFXASCLIN_INSTANCE_MODULE_ASCLIN1_USED  1
#define IFXASCLIN_INSTANCE_MODULE_OPTIONS_USED  1
#define IFXASCLIN_INSTANCE_MODULE_MIN  IFXASCLIN_INSTANCE_MODULE_ASCLIN1
#define IFXASCLIN_INSTANCE_MODULE_MAX  IFXASCLIN_INSTANCE_MODULE_ASCLIN1


// instance data
typedef struct
{
    int instance_id;
} IfxAsclin_cfg_instance_t;

extern const IfxAsclin_cfg_instance_t IfxAsclin_instance_table[]; 

#endif /* _SWP_IFXASCLIN_CFG_INSTANCE_H */
