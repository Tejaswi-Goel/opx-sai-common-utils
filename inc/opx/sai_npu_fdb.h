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
 * \file    sai_npu_fdb.h
 *
 * \brief  Declaration of SAI FDB NPU specific APIs
*/

#if !defined (__SAINPUFDB_H_)
#define __SAINPUFDB_H_

#include "saifdb.h"
#include "saitypes.h"
#include "saistatus.h"
#include "saiswitch.h"
#include "sai_fdb_common.h"

/** SAI NPU FDB -Perform FDB NPU related initialization
    \return Success: SAI_STATUS_SUCCESS
            Failure: One of the failure error codes
*/
typedef sai_status_t (*sai_npu_fdb_init_fn)(void);

/** SAI NPU FDB - Flush all FDB entries based on parameters passed
      \param[in] port_id must be a physical port number. 0 if port match is not used
      \param[in] vlan_id VLAN Identifier between 1 and 4095. 0 if vlan match is not used
      \param[in] delete_all  Flush all entry types.
      \param[in] flush_type  Specific entry type that needs to be flushed.
      \return Success: SAI_STATUS_SUCCESS
              Failure: SAI_STATUS_INVALID_PORT_NUMBER,SAI_STATUS_INVALID_VLAN_ID
*/
typedef sai_status_t (*sai_npu_flush_all_fdb_entries_fn)(sai_object_id_t port_id,
                                                         sai_vlan_id_t vlan_id, bool delete_all,
                                                         sai_fdb_flush_entry_type_t flush_type);

/** SAI NPU FDB - Flush the specified FDB entry
  \param[in] fdb_entry Which has members MAC address and VLAN
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE
 */
typedef sai_status_t (*sai_npu_flush_fdb_entry_fn)(const sai_fdb_entry_t* fdb_entry);

/** SAI NPU FDB - Create FDB entry
  \param[in] fdb_entry Which has members MAC address and VLAN
  \param[in] attr_list The list of attributes. The mandatory attributes are
  \param[in] entry_type Type of the entry- static/dynamic
  \param[in] port_id Port id
  \param[in] action Action - Forward/Trap/Log/Drop
  \param[in] metadata FDB Metadata
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE,SAI_STATUS_INVALID_ATTRIBUTE,
SAI_STATUS_INVALID_ATTR_VALUE,SAI_STATUS_NOT_SUPPORTED
 */

typedef sai_status_t (*sai_npu_create_fdb_entry_fn)(const sai_fdb_entry_t *fdb_entry,
                                                    sai_object_id_t port_id,
                                                    sai_fdb_entry_type_t entry_type,
                                                    sai_packet_action_t action,
                                                    uint_t metadata);

/** SAI NPU FDB - Get FDB Entry from hardware
  \param[in] fdb_entry Which has members MAC address and VLAN
  \param[out] fdb_entry_node which has FDB key, type, action and port
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE,SAI_STATUS_INVALID_ATTRIBUTE,
SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_get_fdb_entry_from_hardware_fn)(const sai_fdb_entry_t *fdb_entry,
                                                               sai_fdb_entry_node_t *fdb_entry_node);

/** SAI NPU FDB - Write FDB Entry to hardware
  \param[in] fdb_entry_node which has FDB key, type, action and port
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE,SAI_STATUS_INVALID_ATTRIBUTE,
SAI_STATUS_INVALID_ATTR_VALUE,SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_write_fdb_entry_to_hardware_fn)(sai_fdb_entry_node_t
                                                               *fdb_entry_node);

/** SAI NPU FDB - Set MAC Learning limit per switch
  \param[in] value Number of MACs to be limited
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_set_switch_max_learned_address_fn)(uint32_t value);


/** SAI NPU FDB - Get MAC Learning limit per switch
  \param[in] value Number of MACs to be limited
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_get_switch_max_learned_address_fn)(uint32_t *value);

/** SAI NPU FDB - Set FDB Unicast Miss action
  \param[in] attr Value should be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_ucast_miss_action_set_fn)(const sai_attribute_t *attr);

/** SAI NPU FDB - Get FDB Unicast Miss action
  \param[out] attr Value would be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_ucast_miss_action_get_fn)(sai_attribute_t *attr);

/** SAI NPU FDB - Set FDB Multicast Miss action
  \param[in] attr Value should be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_mcast_miss_action_set_fn)(const sai_attribute_t *attr);

/** SAI NPU FDB - Get FDB Multicast Miss action
  \param[out] attr Value would be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_mcast_miss_action_get_fn)(sai_attribute_t *attr);

/** SAI NPU FDB - Set FDB Broadcast Miss action
  \param[in] attr Value should be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_bcast_miss_action_set_fn)(const sai_attribute_t *attr);

/** SAI NPU FDB - Get FDB Broadcast Miss action
  \param[out] attr Value would be of type sai_switch_fdb_miss_action_t
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_fdb_bcast_miss_action_get_fn)(sai_attribute_t *attr);
/** SAI NPU FDB - Set Aging time for entries in FDB table
  \param[in] value Aging time in seconds
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_set_aging_time_fn)(uint32_t value);

/** SAI NPU FDB - Get Aging time for entries in FDB table
  \param[out] value Aging time in seconds
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE, SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_get_aging_time_fn)(uint32_t *value);

/** SAI NPU FDB - Register Callback for FDB notification from Application to SAI
  \param[in] fdb_notification_fn Callback function pointer
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE
 */
typedef sai_status_t (*sai_npu_register_callback_fn)(sai_fdb_event_notification_fn
                                                     fdb_notification_fn);

/** SAI NPU FDB - Get FDB table size
  \param[out] attr Attribute containing table size in value.u32
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_FAILURE
 */
typedef sai_status_t (*sai_npu_get_fdb_table_size_fn)(sai_attribute_t *attr);

/** SAI NPU FDB - Enable/Disable flooding of broadcast packets to cpu
  \param[in] enable To Enable or disable
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_bcast_cpu_flood_enable_set_fn)(bool enable);

/** SAI NPU FDB - Enable/Disable flooding of multicast packets to cpu
  \param[in] enable To Enable or disable
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_mcast_cpu_flood_enable_set_fn)(bool enable);

/** SAI NPU FDB - Get flooding setting of broadcast packets to cpu
  \param[out] enable Get whether enabled or disabled
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_bcast_cpu_flood_enable_get_fn)(bool *enable);

/** SAI NPU FDB - Get flooding flooding of multicast packets to cpu
  \param[out] enable Get whether enabled or disabled
  \return Success: SAI_STATUS_SUCCESS
Failure: SAI_STATUS_NOT_SUPPORTED
 */
typedef sai_status_t (*sai_npu_mcast_cpu_flood_enable_get_fn)(bool *enable);


/**
 * @brief FDB NPU API table.
 */
typedef struct _sai_npu_fdb_api_t {
    sai_npu_fdb_init_fn                            fdb_init;
    sai_npu_flush_all_fdb_entries_fn               flush_all_fdb_entries;
    sai_npu_flush_fdb_entry_fn                     flush_fdb_entry;
    sai_npu_create_fdb_entry_fn                    create_fdb_entry;
    sai_npu_get_fdb_entry_from_hardware_fn         get_fdb_entry_from_hardware;
    sai_npu_write_fdb_entry_to_hardware_fn         write_fdb_entry_to_hardware;
    sai_npu_set_aging_time_fn                      set_aging_time;
    sai_npu_get_aging_time_fn                      get_aging_time;
    sai_npu_get_fdb_table_size_fn                  get_fdb_table_size;
    sai_npu_register_callback_fn                   register_callback;
    sai_npu_set_switch_max_learned_address_fn      set_switch_max_learned_address;
    sai_npu_get_switch_max_learned_address_fn      get_switch_max_learned_address;
    sai_npu_fdb_ucast_miss_action_set_fn           fdb_ucast_miss_action_set;
    sai_npu_fdb_ucast_miss_action_get_fn           fdb_ucast_miss_action_get;
    sai_npu_fdb_mcast_miss_action_set_fn           fdb_mcast_miss_action_set;
    sai_npu_fdb_mcast_miss_action_get_fn           fdb_mcast_miss_action_get;
    sai_npu_fdb_bcast_miss_action_set_fn           fdb_bcast_miss_action_set;
    sai_npu_fdb_bcast_miss_action_get_fn           fdb_bcast_miss_action_get;
    sai_npu_bcast_cpu_flood_enable_set_fn          bcast_cpu_flood_enable_set;
    sai_npu_mcast_cpu_flood_enable_set_fn          mcast_cpu_flood_enable_set;
    sai_npu_bcast_cpu_flood_enable_get_fn          bcast_cpu_flood_enable_get;
    sai_npu_mcast_cpu_flood_enable_get_fn          mcast_cpu_flood_enable_get;

} sai_npu_fdb_api_t;

#endif