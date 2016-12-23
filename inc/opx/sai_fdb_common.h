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
 * \file    sai_fdb_common.h
 *
 * \brief  FDB Data Structures. To be interally used by SAI
*/


/** \defgroup SAIFDB COMMON - SAI FDB Data structures and common definitions
* To be internally used by SAI
*
* \{
*/


#if !defined (__SAIFDBCOMMON_H_)
#define __SAIFDBCOMMON_H_

#include "saitypes.h"
#include "saiswitch.h"
#include "saifdb.h"
#include "std_radix.h"
#include "std_radical.h"
#include "sai_event_log.h"

/** FDB Entry key: Key used to save FDB entry in cache*/
typedef struct _sai_fdb_entry_key_t {
    /*vlan_id: represents the VLAN identifier of the entry*/
    sai_vlan_id_t vlan_id;
    /*mac_address: SAI Format MAC Address*/
    sai_mac_t mac_address;
}sai_fdb_entry_key_t;

/** FDB Entry Node: The full FDB node structure*/
typedef struct _sai_fdb_entry_node_t {
    /*fdb_rt_head: Radix tree head*/
    std_rt_head fdb_rt_head;
    /*fdb_key: Key for the FDB node*/
    sai_fdb_entry_key_t fdb_key;
    /*port_id: Port on which FDB entry is learnt*/
    sai_object_id_t      port_id;
    /*entry_type: Type of the entry either static or dynamic*/
    sai_fdb_entry_type_t entry_type;
    /*action: FDB action - Forward/Trap/Log/Drop*/
    sai_packet_action_t action;
    /* metadata: FDB Meta Data */
    uint_t metadata;
}sai_fdb_entry_node_t;

/** FDB Registered Node: The full FDB registered node structure*/
typedef struct _sai_fdb_registered_node_t {
    /*fdb_radical_head: Radical tree head*/
    std_radical_head_t fdb_radical_head;
    /*fdb_key: Key for the FDB node*/
    sai_fdb_entry_key_t fdb_key;
    /*port_id: Port on which FDB entry is learnt*/
    sai_object_id_t     port_id;
    /*node_in_cl: If the node is currently in the changelist*/
    bool                node_in_cl;
    /*fdb_event: FDB event associated with the node*/
    sai_fdb_event_t     fdb_event;
} sai_fdb_registered_node_t;

typedef struct _sai_fdb_notification_data_t {
    /*fdb_entry: FDB entry*/
    sai_fdb_entry_t     fdb_entry;
    /*port_id: Port on which FDB entry is learnt*/
    sai_object_id_t     port_id;
    /*fdb_event: FDB event associated with the data*/
    sai_fdb_event_t     fdb_event;

} sai_fdb_notification_data_t;


typedef struct _sai_fdb_global_data_t {
    /*sai_global_fdb_tree: FDB entry global tree*/
    std_rt_table       *sai_global_fdb_tree;
    /*sai_registered_fdb_entry_tree: Tree containing registered FDB entries*/
    std_rt_table       *sai_registered_fdb_entry_tree;
    /*fdb_notification_marker: Marker node for changelist in registered FDB entry tree*/
    std_radical_ref_t  fdb_marker;
    /*num_notifications: Number of notifications pending to be sent*/
    uint_t             num_notifications;
    /*cur_notification_idx: Current number of notification be added to array by notification thread*/
    uint_t             cur_notification_idx;
} sai_fdb_global_data_t;
#define SAI_FDB_ENTRY_KEY_SIZE (sizeof(sai_fdb_entry_key_t)*8)

#define SAI_MAX_FDB_ATTRIBUTES 3
#define SAI_MAC_NUM_BYTES 6
#define SAI_MAC_NUM_CHAR_PER_BYTE 3
#define SAI_MAC_STR_LEN (SAI_MAC_NUM_CHAR_PER_BYTE*SAI_MAC_NUM_BYTES)
#define SAI_FDB_LEARN_LIMIT_DISABLE 0
#define SAI_FDB_MAX_NOTIFICATION_NODES 50

/** Logging utility for SAI FDB API */
#define SAI_FDB_LOG(level, msg, ...) \
    do { \
        if (sai_is_log_enabled (SAI_API_FDB, level)) { \
            SAI_LOG_UTIL(ev_log_t_SAI_FDB, level, msg, ##__VA_ARGS__); \
        } \
    } while (0)

/** Per log level based macros for SAI FDB API */
#define SAI_FDB_LOG_TRACE(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_DEBUG, msg, ##__VA_ARGS__)

#define SAI_FDB_LOG_CRIT(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_CRITICAL, msg, ##__VA_ARGS__)

#define SAI_FDB_LOG_ERR(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)

#define SAI_FDB_LOG_INFO(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_INFO, msg, ##__VA_ARGS__)

#define SAI_FDB_LOG_WARN(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_WARN, msg, ##__VA_ARGS__)

#define SAI_FDB_LOG_NTC(msg, ...) \
        SAI_FDB_LOG (SAI_LOG_LEVEL_NOTICE, msg, ##__VA_ARGS__)

#endif
/**
\}
*/
