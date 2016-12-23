/************************************************************************
* * LEGALESE:   "Copyright (c) 2015, Dell Inc. All rights reserved."
* *
* * This source code is confidential, proprietary, and contains trade
* * secrets that are the sole property of Dell Inc.
* * Copy and/or distribution of this source code or disassembly or reverse
* * engineering of the resultant object code are strictly forbidden without
* * the written consent of Dell Inc.
* *
************************************************************************/
/***
 * \file    sai_vlan_common.h
 *
 * \brief SAI VLAN data structures.To be interally used by SAI
*/


/** \defgroup SAIVLAN Common - SAI VLAN Data structures and common definitions
* To be internally used by SAI
*
* \{
*/

#if !defined (__SAIVLANCOMMON_H_)
#define __SAIVLANCOMMON_H_

#include "saitypes.h"
#include "saivlan.h"
#include "std_llist.h"
#include "std_struct_utils.h"
#include "sai_event_log.h"

#define SAI_MIN_VLAN_TAG_ID 1
#define SAI_MAX_VLAN_TAG_ID 4095
#define VLAN_UNDEF (0)
#define SAI_INIT_DEFAULT_VLAN 1
#define SAI_DEF_VLAN_TAGGING_MODE SAI_VLAN_TAGGING_MODE_UNTAGGED
/*VLAN port node: A node in linked list*/
typedef struct _sai_vlan_port_node_t{
    /*node: Linked list node*/
    std_dll node;
    /*vlan_port: Port and tagging mode*/
    sai_vlan_port_t vlan_port;
}sai_vlan_port_node_t;

/*VLAN Global cache node: List of ports in the vlan*/
typedef struct _sai_vlan_global_cache_node_t{
    /*port_list: List of ports*/
    std_dll_head port_list;
    /*vlan_id: VLAN identifier*/
    sai_vlan_id_t vlan_id;
    /*port_cout: Number of ports in the VLAN*/
    unsigned int port_count;
    /*max_learned_address: Max FDB learn limit*/
    unsigned int max_learned_address;
    /*learn_disable: To disable learning on a VLAN*/
    bool learn_disable;
    /*meta_data: To associate meta data on a VLAN*/
    unsigned int meta_data;
}sai_vlan_global_cache_node_t;

/*Port VLAN Counter: A node in linked list*/
typedef struct _sai_port_vlan_counter_t{
    /*node: Linked list node*/
    std_dll node;
    /*port_id: sai port identifier*/
    sai_object_id_t port_id;
    /*vlan_count: Number of VLANS in port*/
    unsigned int vlan_count;
}sai_port_vlan_counter_t;

#define SAI_PORTV_VLAN_COUNTER_OFFSET STD_STR_OFFSET_OF(sai_port_vlan_counter_t, port_id)
#define SAI_PORTV_VLAN_COUNTER_SIZE STD_STR_SIZE_OF(sai_port_vlan_counter_t, port_id)

/** Logging utility for SAI VLAN API */
#define SAI_VLAN_LOG(level, msg, ...) \
    do { \
        if (sai_is_log_enabled (SAI_API_VLAN, level)) { \
            SAI_LOG_UTIL(ev_log_t_SAI_VLAN, level, msg, ##__VA_ARGS__); \
        } \
    } while (0)

/** Per log level based macros for SAI VLAN API */
#define SAI_VLAN_LOG_TRACE(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_DEBUG, msg, ##__VA_ARGS__)

#define SAI_VLAN_LOG_CRIT(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_CRITICAL, msg, ##__VA_ARGS__)

#define SAI_VLAN_LOG_ERR(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)

#define SAI_VLAN_LOG_INFO(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_INFO, msg, ##__VA_ARGS__)

#define SAI_VLAN_LOG_WARN(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_WARN, msg, ##__VA_ARGS__)

#define SAI_VLAN_LOG_NTC(msg, ...) \
        SAI_VLAN_LOG (SAI_LOG_LEVEL_NOTICE, msg, ##__VA_ARGS__)

#endif

/**
\}
*/
