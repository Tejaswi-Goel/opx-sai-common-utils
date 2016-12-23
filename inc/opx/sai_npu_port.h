/************************************************************************
* LEGALESE:   "Copyright (c); 2015, Dell Inc. All rights reserved."
*
* This source code is confidential, proprietary, and contains trade
* secrets that are the sole property of Dell Inc.
* Copy and/or distribution of this source code or disassembly or reverse
* engineering of the resultant object code are strictly forbidden without
* the written consent of Dell Inc.
*
************************************************************************/
/**
* @file sai_npu_port.h
*
* @brief This file contains API signatures for SAI NPU port component.
*        SAI Common use these API to Get/Set Port level Attributes and
*        to register for link state change notifications
*
*******************************************************************************/

/* OPENSOURCELICENSE */

#ifndef __SAI_NPU_PORT_H__
#define __SAI_NPU_PORT_H__

#include "saitypes.h"
#include "saistatus.h"
#include "saiport.h"

#include "std_type_defs.h"

/** \defgroup SAINPUPORTAPI SAI - NPU port Functionality
 *   Port functions for SAI NPU component
 *
 * \ingroup SAIPORTAPI
 * \{
 */

/**
 * @brief Set port attribute
 *
 * @param[in] port_id  Port Identifier
 * @param[in] attr  Attribute id and value
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_set_attribute_fn)(sai_object_id_t port_id,
                                                      const sai_attribute_t *attr);

/**
 * @brief Get Port attributes
 *
 * @param[in] port_id  Port Identifier
 * @param[in] attr_count  The number of attributes in the attribute array
 * @param[inout] attr_list The list of attributes in sai_attribute_t,
 *  where attr_id is the input and sai_attribute_value_t is the output value
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_get_attribute_fn)(sai_object_id_t port_id,
                                                      uint_t attr_count,
                                                      sai_attribute_t *attr_list);

/**
 * @brief Get statistics counters
 *
 * @param[in] port_id  Port Identifier
 * @param[in] counter_ids Types of counter to enable
 * @param[in] number_of_counters  Number of counters to get
 * @param[out] counters  Values of the counters
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_get_stats_fn)(sai_object_id_t port_id,
                                                  const sai_port_stat_t *counter_ids,
                                                  uint32_t number_of_counters,
                                                  uint64_t* counters);

/**
 * @brief Clear statistics counters of the specified port
 *
 * @param[in] port_id Port Identifier
 * @param[in] counter_ids Types of counter to clear
 * @param[in] number_of_counters Number of counters to clear
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_clear_stats_fn)(sai_object_id_t port_id,
                                                    const sai_port_stat_t *counter_ids,
                                                    uint32_t number_of_counters);

/**
 * @brief Clear all statistics counters of the specified port
 *
 * @param[in] port_id Port Identifier
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_clear_all_stats_fn) (sai_object_id_t port_id);

/**
 * @brief Register Callback for link state notification from SAI to Adapter Host
 *
 * @param[in] link_state_cb_fn link state callback function; use NULL as input
 *            to unregister from the callback notifications
 * @warning Calling this API for the second time will overwrite the existing
 *          registered function
 */
typedef void (*sai_npu_reg_link_state_cb_fn)(
                             sai_port_state_change_notification_fn link_state_cb_fn);

/**
 * @brief Set the port breakout mode for the given set of port(s) in the port list.
 *
 * @param[in] portbreakout  pointer consisting of breakout mode to be set and list of
 *                          ports(s) to be configured
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_breakout_set_fn)(const sai_port_breakout_t *portbreakout);

/**
 * @brief Update the port packet switching mode based on the port event type ADD/DELETE and
 *  the port operating speed. As packet switching mode depends on port speed, it should be
 *  updated for events like ADD/DELETE during port breakout.
 *
 * @param[in] count Count of port events
 * @param[in] data pointer to list of port id and its event type Add/Delete
 *
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_npu_port_switching_mode_update_fn)(uint32_t count,
                                                              sai_port_event_notification_t *data);

/**
 * @brief PORT NPU API table.
 */
typedef struct _sai_npu_port_api_t {
    sai_npu_port_set_attribute_fn               port_set_attribute;
    sai_npu_port_get_attribute_fn               port_get_attribute;
    sai_npu_port_get_stats_fn                   port_get_stats;
    sai_npu_port_clear_stats_fn                 port_clear_stats;
    sai_npu_port_clear_all_stats_fn             port_clear_all_stats;
    sai_npu_reg_link_state_cb_fn                reg_link_state_cb;
    sai_npu_port_breakout_set_fn                breakout_set;
    sai_npu_port_switching_mode_update_fn       switching_mode_update;

} sai_npu_port_api_t;

/**
 * \}
 */

#endif /* __SAI_NPU_PORT_H__ */
