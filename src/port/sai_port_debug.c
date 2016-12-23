/************************************************************************
* LEGALESE:   "Copyright (c) 2015, Dell Inc. All rights reserved."
*
* This source code is confidential, proprietary, and contains trade
* secrets that are the sole property of Dell Inc.
* Copy and/or distribution of this source code or disassembly or reverse
* engineering of the resultant object code are strictly forbidden without
* the written consent of Dell Inc.
*
************************************************************************/
/**
* @file sai_port_debug.c
*
* @brief This file contains Port related debugging utilities.
*
*************************************************************************/
#include <stdio.h>
#include <inttypes.h>

#include "saiswitch.h"
#include "saitypes.h"
#include "saiport.h"
#include "saistatus.h"

#include "sai_debug_utils.h"
#include "sai_port_common.h"
#include "sai_port_utils.h"
#include "sai_switch_utils.h"

void sai_port_attr_info_dump_port(sai_object_id_t port_id)
{
    sai_port_attr_info_t *port_attr_info = sai_port_attr_info_get(port_id);
    if(port_attr_info == NULL)   {
        return;
    }

    SAI_DEBUG("###### SAI port attributes default/configured "
              "info of port: 0x%"PRIx64"", port_id);

    SAI_DEBUG("SAI_PORT_ATTR_OPER_STATUS is %d", port_attr_info->oper_status);

    SAI_DEBUG("SAI_PORT_ATTR_SPEED is %d", port_attr_info->speed);

    SAI_DEBUG("SAI_PORT_ATTR_FULL_DUPLEX_MODE is %d", port_attr_info->duplex);

    SAI_DEBUG("SAI_PORT_ATTR_ADMIN_STATE is %s",
              (port_attr_info->admin_state) ? "enabled" : "disabled");

    SAI_DEBUG("SAI_PORT_ATTR_MEDIA_TYPE is %d", port_attr_info->media_type);

    SAI_DEBUG("SAI_PORT_ATTR_DEFAULT_VLAN is %d", port_attr_info->default_vlan);

    SAI_DEBUG("SAI_PORT_ATTR_DEFAULT_VLAN_PRIORITY is %d",
              port_attr_info->default_vlan_priority);

    SAI_DEBUG("SAI_PORT_ATTR_INGRESS_FILTERING is %d", port_attr_info->ingress_filtering);

    SAI_DEBUG("SAI_PORT_ATTR_DROP_UNTAGGED is %s",
              (port_attr_info->drop_untagged) ? "enabled" : "disabled");

    SAI_DEBUG("SAI_PORT_ATTR_DROP_TAGGED is %s",
              (port_attr_info->drop_tagged) ? "enabled" : "disabled");

    SAI_DEBUG("SAI_PORT_ATTR_INTERNAL_LOOPBACK is %d", port_attr_info->internal_loopback);

    SAI_DEBUG("SAI_PORT_ATTR_FDB_LEARNING is %d", port_attr_info->fdb_learning);

    SAI_DEBUG("SAI_PORT_ATTR_UPDATE_DSCP is %s",
              (port_attr_info->update_dscp) ? "enabled" : "disabled");

    SAI_DEBUG("SAI_PORT_ATTR_MTU is %d", port_attr_info->mtu);

    SAI_DEBUG("SAI_PORT_ATTR_MAX_LEARNED_ADDRESSES is %d",
              port_attr_info->max_learned_address);

    SAI_DEBUG("SAI_PORT_ATTR_FDB_LEARNING_LIMIT_VIOLATION is %d",
              port_attr_info->fdb_learn_limit_violation);
}

void sai_port_info_dump_port(sai_object_id_t port_id)
{
    sai_port_info_t *port_info = sai_port_info_get(port_id);

    if(port_info == NULL) {
        SAI_DEBUG("Invalid port 0x%"PRIx64"", port_id);
        return;
    }

    SAI_DEBUG("###### SAI port object id is: 0x%"PRIx64"", port_info->sai_port_id);

    SAI_DEBUG("Port is: %s", (port_info->port_valid) ? "valid" : "invalid");

    SAI_DEBUG("Logical/Local port is: %d", port_info->local_port_id);

    SAI_DEBUG("Physical port id is: %d", port_info->phy_port_id);

    SAI_DEBUG("Port group is: %d", port_info->port_group);

    SAI_DEBUG("Phy type is: %s",
              (port_info->phy_type == SAI_PORT_PHY_INTERNAL) ? "Internal" : "External");

    SAI_DEBUG("Forwarding mode is: %s", sai_port_forwarding_mode_to_str(port_info->fwd_mode));

    SAI_DEBUG("External Phy address is: %d", port_info->ext_phy_addr);

    SAI_DEBUG("supported capabilities bitmap 0x%lx", port_info->port_supported_capb);

    SAI_DEBUG("Enabled capabilities bitmap 0x%lx", port_info->port_enabled_capb);

    SAI_DEBUG("Max Lanes per port is: %d", port_info->max_lanes_per_port);

    SAI_DEBUG("Active lanes bitmap is: 0x%lx", port_info->port_lane_bmap);

    SAI_DEBUG("Speed is: %d", port_info->port_speed);

    SAI_DEBUG("Media type is: %d", port_info->media_type);

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_HUNDRED_MEG) {
        SAI_DEBUG("Port supports 100M speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_GIG) {
        SAI_DEBUG("Port supports 1G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_TEN_GIG) {
        SAI_DEBUG("Port supports 10G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_TWENTY_FIVE_GIG) {
        SAI_DEBUG("Port supports 25G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_FORTY_GIG) {
        SAI_DEBUG("Port supports 40G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_FORTY_TWO_GIG) {
        SAI_DEBUG("Port supports 42G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_FIFTY_GIG) {
        SAI_DEBUG("Port supports 50G speed");
    }

    if(port_info->port_speed_capb & SAI_PORT_CAP_SPEED_HUNDRED_GIG) {
        SAI_DEBUG("Port supports 100G speed");
    }
}

void sai_port_capability_flag_dump(void)
{
    SAI_DEBUG("sai_port_capability_t Enum values");

    SAI_DEBUG("SAI_PORT_CAP_BREAKOUT_MODE is 0x%x", SAI_PORT_CAP_BREAKOUT_MODE);
    SAI_DEBUG("SAI_PORT_CAP_BREAKOUT_MODE_1X is 0x%x", SAI_PORT_CAP_BREAKOUT_MODE_1X);
    SAI_DEBUG("SAI_PORT_CAP_BREAKOUT_MODE_2X is 0x%x", SAI_PORT_CAP_BREAKOUT_MODE_2X);
    SAI_DEBUG("SAI_PORT_CAP_BREAKOUT_MODE_4X is 0x%x", SAI_PORT_CAP_BREAKOUT_MODE_4X);
}

/* sai_port_info_t structure dump */
void sai_port_info_dump_all(void)
{
    sai_port_info_t *port_info = NULL;

    SAI_DEBUG("###### PORT INFO TABLE DUMP #######");

    for (port_info = sai_port_info_getfirst(); (port_info != NULL);
         port_info = sai_port_info_getnext(port_info)) {

        sai_port_info_dump_port(port_info->sai_port_id);
        sai_port_attr_info_dump_port(port_info->sai_port_id);
    }

    sai_port_capability_flag_dump();
}
