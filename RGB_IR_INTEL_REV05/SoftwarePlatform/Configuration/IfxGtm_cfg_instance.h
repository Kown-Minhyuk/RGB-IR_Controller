/*
 *  Software Platform Generated File
 *  --------------------------------
 */

#ifndef _SWP_IFXGTM_CFG_INSTANCE_H
#define _SWP_IFXGTM_CFG_INSTANCE_H

#include "IfxGtm_cfg.h"


#define IFXGTM_INSTANCE_MODULE_GTM_TOM0  &MODULE_GTM0
#define IFXGTM_INSTANCE_MODULE_GTM_TOM1  &MODULE_GTM0

#define IFXGTM_INSTANCE_MODULE_GTM_TOM0_USED  1
#define IFXGTM_INSTANCE_MODULE_GTM_TOM1_USED  0
#define IFXGTM_INSTANCE_MODULE_OPTIONS_USED  1
#define IFXGTM_INSTANCE_MODULE_MIN  IFXGTM_INSTANCE_MODULE_GTM_TOM0
#define IFXGTM_INSTANCE_MODULE_MAX  IFXGTM_INSTANCE_MODULE_GTM_TOM0


// instance data
typedef struct
{
    int instance_id;
} IfxGtm_cfg_instance_t;

extern const IfxGtm_cfg_instance_t IfxGtm_instance_table[]; 

#endif /* _SWP_IFXGTM_CFG_INSTANCE_H */
