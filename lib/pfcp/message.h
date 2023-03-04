/*
 * Copyright (C) 2019-2022 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*******************************************************************************
 * This file had been created by pfcp-tlv.py script v0.1.0
 * Please do not modify this file but regenerate it via script.
 * Created on: 2023-03-05 00:10:36.099999 by acetcom
 * from 29244-g91-modified.docx
 ******************************************************************************/

#if !defined(OGS_PFCP_INSIDE) && !defined(OGS_PFCP_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_PFCP_MESSAGE_H
#define OGS_PFCP_MESSAGE_H

#ifdef __cplusplus
    extern "C" {
#endif

    /* 5.1 General format */
#define OGS_PFCP_HEADER_LEN 16
#define OGS_PFCP_SEID_LEN   8
    typedef struct ogs_pfcp_header_s {
        union {
            struct {
            ED4(uint8_t version:3;,
                uint8_t spare1:3;,
                uint8_t mp:1;,
                uint8_t seid_presence:1;)
            };
            uint8_t flags;
        };
        uint8_t type;
        uint16_t length;
        union {
            struct {
                uint64_t seid;
                /* sqn : 31bit ~ 8bit, spare : 7bit ~ 0bit */
#define OGS_PFCP_XID_TO_SQN(__xid) htobe32(((__xid) << 8))
#define OGS_PFCP_SQN_TO_XID(__sqn) (be32toh(__sqn) >> 8)
                uint32_t sqn;
            };
            /* sqn : 31bit ~ 8bit, spare : 7bit ~ 0bit */
            uint32_t sqn_only;
        };
    } __attribute__ ((packed)) ogs_pfcp_header_t;

    /* PFCP message type */
#define OGS_PFCP_HEARTBEAT_REQUEST_TYPE 1
#define OGS_PFCP_HEARTBEAT_RESPONSE_TYPE 2
#define OGS_PFCP_PFD_MANAGEMENT_REQUEST_TYPE 3
#define OGS_PFCP_PFD_MANAGEMENT_RESPONSE_TYPE 4
#define OGS_PFCP_ASSOCIATION_SETUP_REQUEST_TYPE 5
#define OGS_PFCP_ASSOCIATION_SETUP_RESPONSE_TYPE 6
#define OGS_PFCP_ASSOCIATION_UPDATE_REQUEST_TYPE 7
#define OGS_PFCP_ASSOCIATION_UPDATE_RESPONSE_TYPE 8
#define OGS_PFCP_ASSOCIATION_RELEASE_REQUEST_TYPE 9
#define OGS_PFCP_ASSOCIATION_RELEASE_RESPONSE_TYPE 10
#define OGS_PFCP_VERSION_NOT_SUPPORTED_RESPONSE_TYPE 11
#define OGS_PFCP_NODE_REPORT_REQUEST_TYPE 12
#define OGS_PFCP_NODE_REPORT_RESPONSE_TYPE 13
#define OGS_PFCP_SESSION_SET_DELETION_REQUEST_TYPE 14
#define OGS_PFCP_SESSION_SET_DELETION_RESPONSE_TYPE 15
#define OGS_PFCP_SESSION_ESTABLISHMENT_REQUEST_TYPE 50
#define OGS_PFCP_SESSION_ESTABLISHMENT_RESPONSE_TYPE 51
#define OGS_PFCP_SESSION_MODIFICATION_REQUEST_TYPE 52
#define OGS_PFCP_SESSION_MODIFICATION_RESPONSE_TYPE 53
#define OGS_PFCP_SESSION_DELETION_REQUEST_TYPE 54
#define OGS_PFCP_SESSION_DELETION_RESPONSE_TYPE 55
#define OGS_PFCP_SESSION_REPORT_REQUEST_TYPE 56
#define OGS_PFCP_SESSION_REPORT_RESPONSE_TYPE 57

#define OGS_PFCP_CREATE_PDR_TYPE 1
#define OGS_PFCP_PDI_TYPE 2
#define OGS_PFCP_CREATE_FAR_TYPE 3
#define OGS_PFCP_FORWARDING_PARAMETERS_TYPE 4
#define OGS_PFCP_DUPLICATING_PARAMETERS_TYPE 5
#define OGS_PFCP_CREATE_URR_TYPE 6
#define OGS_PFCP_CREATE_QER_TYPE 7
#define OGS_PFCP_CREATED_PDR_TYPE 8
#define OGS_PFCP_UPDATE_PDR_TYPE 9
#define OGS_PFCP_UPDATE_FAR_TYPE 10
#define OGS_PFCP_UPDATE_FORWARDING_PARAMETERS_TYPE 11
#define OGS_PFCP_UPDATE_BAR_PFCP_SESSION_REPORT_RESPONSE_TYPE 12
#define OGS_PFCP_UPDATE_URR_TYPE 13
#define OGS_PFCP_UPDATE_QER_TYPE 14
#define OGS_PFCP_REMOVE_PDR_TYPE 15
#define OGS_PFCP_REMOVE_FAR_TYPE 16
#define OGS_PFCP_REMOVE_URR_TYPE 17
#define OGS_PFCP_REMOVE_QER_TYPE 18
#define OGS_PFCP_CAUSE_TYPE 19
#define OGS_PFCP_SOURCE_INTERFACE_TYPE 20
#define OGS_PFCP_F_TEID_TYPE 21
#define OGS_PFCP_NETWORK_INSTANCE_TYPE 22
#define OGS_PFCP_SDF_FILTER_TYPE 23
#define OGS_PFCP_APPLICATION_ID_TYPE 24
#define OGS_PFCP_GATE_STATUS_TYPE 25
#define OGS_PFCP_MBR_TYPE 26
#define OGS_PFCP_GBR_TYPE 27
#define OGS_PFCP_QER_CORRELATION_ID_TYPE 28
#define OGS_PFCP_PRECEDENCE_TYPE 29
#define OGS_PFCP_TRANSPORT_LEVEL_MARKING_TYPE 30
#define OGS_PFCP_VOLUME_THRESHOLD_TYPE 31
#define OGS_PFCP_TIME_THRESHOLD_TYPE 32
#define OGS_PFCP_MONITORING_TIME_TYPE 33
#define OGS_PFCP_SUBSEQUENT_VOLUME_THRESHOLD_TYPE 34
#define OGS_PFCP_SUBSEQUENT_TIME_THRESHOLD_TYPE 35
#define OGS_PFCP_INACTIVITY_DETECTION_TIME_TYPE 36
#define OGS_PFCP_REPORTING_TRIGGERS_TYPE 37
#define OGS_PFCP_REDIRECT_INFORMATION_TYPE 38
#define OGS_PFCP_REPORT_TYPE_TYPE 39
#define OGS_PFCP_OFFENDING_IE_TYPE 40
#define OGS_PFCP_FORWARDING_POLICY_TYPE 41
#define OGS_PFCP_DESTINATION_INTERFACE_TYPE 42
#define OGS_PFCP_UP_FUNCTION_FEATURES_TYPE 43
#define OGS_PFCP_APPLY_ACTION_TYPE 44
#define OGS_PFCP_DOWNLINK_DATA_SERVICE_INFORMATION_TYPE 45
#define OGS_PFCP_DOWNLINK_DATA_NOTIFICATION_DELAY_TYPE 46
#define OGS_PFCP_DL_BUFFERING_DURATION_TYPE 47
#define OGS_PFCP_DL_BUFFERING_SUGGESTED_PACKET_COUNT_TYPE 48
#define OGS_PFCP_PFCPSMREQ_FLAGS_TYPE 49
#define OGS_PFCP_PFCPSRRSP_FLAGS_TYPE 50
#define OGS_PFCP_LOAD_CONTROL_INFORMATION_TYPE 51
#define OGS_PFCP_SEQUENCE_NUMBER_TYPE 52
#define OGS_PFCP_METRIC_TYPE 53
#define OGS_PFCP_OVERLOAD_CONTROL_INFORMATION_TYPE 54
#define OGS_PFCP_TIMER_TYPE 55
#define OGS_PFCP_PDR_ID_TYPE 56
#define OGS_PFCP_F_SEID_TYPE 57
#define OGS_PFCP_APPLICATION_ID_S_PFDS_TYPE 58
#define OGS_PFCP_PFD_CONTEXT_TYPE 59
#define OGS_PFCP_NODE_ID_TYPE 60
#define OGS_PFCP_PFD_CONTENTS_TYPE 61
#define OGS_PFCP_MEASUREMENT_METHOD_TYPE 62
#define OGS_PFCP_USAGE_REPORT_TRIGGER_TYPE 63
#define OGS_PFCP_MEASUREMENT_PERIOD_TYPE 64
#define OGS_PFCP_FQ_CSID_TYPE 65
#define OGS_PFCP_VOLUME_MEASUREMENT_TYPE 66
#define OGS_PFCP_DURATION_MEASUREMENT_TYPE 67
#define OGS_PFCP_APPLICATION_DETECTION_INFORMATION_TYPE 68
#define OGS_PFCP_TIME_OF_FIRST_PACKET_TYPE 69
#define OGS_PFCP_TIME_OF_LAST_PACKET_TYPE 70
#define OGS_PFCP_QUOTA_HOLDING_TIME_TYPE 71
#define OGS_PFCP_DROPPED_DL_TRAFFIC_THRESHOLD_TYPE 72
#define OGS_PFCP_VOLUME_QUOTA_TYPE 73
#define OGS_PFCP_TIME_QUOTA_TYPE 74
#define OGS_PFCP_START_TIME_TYPE 75
#define OGS_PFCP_END_TIME_TYPE 76
#define OGS_PFCP_QUERY_URR_TYPE 77
#define OGS_PFCP_USAGE_REPORT_SESSION_MODIFICATION_RESPONSE_TYPE 78
#define OGS_PFCP_USAGE_REPORT_SESSION_DELETION_RESPONSE_TYPE 79
#define OGS_PFCP_USAGE_REPORT_SESSION_REPORT_REQUEST_TYPE 80
#define OGS_PFCP_URR_ID_TYPE 81
#define OGS_PFCP_LINKED_URR_ID_TYPE 82
#define OGS_PFCP_DOWNLINK_DATA_REPORT_TYPE 83
#define OGS_PFCP_OUTER_HEADER_CREATION_TYPE 84
#define OGS_PFCP_CREATE_BAR_TYPE 85
#define OGS_PFCP_UPDATE_BAR_SESSION_MODIFICATION_REQUEST_TYPE 86
#define OGS_PFCP_REMOVE_BAR_TYPE 87
#define OGS_PFCP_BAR_ID_TYPE 88
#define OGS_PFCP_CP_FUNCTION_FEATURES_TYPE 89
#define OGS_PFCP_USAGE_INFORMATION_TYPE 90
#define OGS_PFCP_APPLICATION_INSTANCE_ID_TYPE 91
#define OGS_PFCP_FLOW_INFORMATION_TYPE 92
#define OGS_PFCP_UE_IP_ADDRESS_TYPE 93
#define OGS_PFCP_PACKET_RATE_TYPE 94
#define OGS_PFCP_OUTER_HEADER_REMOVAL_TYPE 95
#define OGS_PFCP_RECOVERY_TIME_STAMP_TYPE 96
#define OGS_PFCP_DL_FLOW_LEVEL_MARKING_TYPE 97
#define OGS_PFCP_HEADER_ENRICHMENT_TYPE 98
#define OGS_PFCP_ERROR_INDICATION_REPORT_TYPE 99
#define OGS_PFCP_MEASUREMENT_INFORMATION_TYPE 100
#define OGS_PFCP_NODE_REPORT_TYPE_TYPE 101
#define OGS_PFCP_USER_PLANE_PATH_FAILURE_REPORT_TYPE 102
#define OGS_PFCP_REMOTE_GTP_U_PEER_TYPE 103
#define OGS_PFCP_UR_SEQN_TYPE 104
#define OGS_PFCP_UPDATE_DUPLICATING_PARAMETERS_TYPE 105
#define OGS_PFCP_ACTIVATE_PREDEFINED_RULES_TYPE 106
#define OGS_PFCP_DEACTIVATE_PREDEFINED_RULES_TYPE 107
#define OGS_PFCP_FAR_ID_TYPE 108
#define OGS_PFCP_QER_ID_TYPE 109
#define OGS_PFCP_OCI_FLAGS_TYPE 110
#define OGS_PFCP_PFCP_ASSOCIATION_RELEASE_REQUEST_TYPE 111
#define OGS_PFCP_GRACEFUL_RELEASE_PERIOD_TYPE 112
#define OGS_PFCP_PDN_TYPE_TYPE 113
#define OGS_PFCP_FAILED_RULE_ID_TYPE 114
#define OGS_PFCP_TIME_QUOTA_MECHANISM_TYPE 115
#define OGS_PFCP_USER_PLANE_IP_RESOURCE_INFORMATION_TYPE 116
#define OGS_PFCP_USER_PLANE_INACTIVITY_TIMER_TYPE 117
#define OGS_PFCP_AGGREGATED_URRS_TYPE 118
#define OGS_PFCP_MULTIPLIER_TYPE 119
#define OGS_PFCP_AGGREGATED_URR_ID_TYPE 120
#define OGS_PFCP_SUBSEQUENT_VOLUME_QUOTA_TYPE 121
#define OGS_PFCP_SUBSEQUENT_TIME_QUOTA_TYPE 122
#define OGS_PFCP_RQI_TYPE 123
#define OGS_PFCP_QFI_TYPE 124
#define OGS_PFCP_QUERY_URR_REFERENCE_TYPE 125
#define OGS_PFCP_ADDITIONAL_USAGE_REPORTS_INFORMATION_TYPE 126
#define OGS_PFCP_CREATE_TRAFFIC_ENDPOINT_TYPE 127
#define OGS_PFCP_CREATED_TRAFFIC_ENDPOINT_TYPE 128
#define OGS_PFCP_UPDATE_TRAFFIC_ENDPOINT_TYPE 129
#define OGS_PFCP_REMOVE_TRAFFIC_ENDPOINT_TYPE 130
#define OGS_PFCP_TRAFFIC_ENDPOINT_ID_TYPE 131
#define OGS_PFCP_ETHERNET_PACKET_FILTER_TYPE 132
#define OGS_PFCP_MAC_ADDRESS_TYPE 133
#define OGS_PFCP_C_TAG_TYPE 134
#define OGS_PFCP_S_TAG_TYPE 135
#define OGS_PFCP_ETHERTYPE_TYPE 136
#define OGS_PFCP_PROXYING_TYPE 137
#define OGS_PFCP_ETHERNET_FILTER_ID_TYPE 138
#define OGS_PFCP_ETHERNET_FILTER_PROPERTIES_TYPE 139
#define OGS_PFCP_SUGGESTED_BUFFERING_PACKETS_COUNT_TYPE 140
#define OGS_PFCP_USER_ID_TYPE 141
#define OGS_PFCP_ETHERNET_PDU_SESSION_INFORMATION_TYPE 142
#define OGS_PFCP_ETHERNET_TRAFFIC_INFORMATION_TYPE 143
#define OGS_PFCP_MAC_ADDRESSES_DETECTED_TYPE 144
#define OGS_PFCP_MAC_ADDRESSES_REMOVED_TYPE 145
#define OGS_PFCP_ETHERNET_INACTIVITY_TIMER_TYPE 146
#define OGS_PFCP_ADDITIONAL_MONITORING_TIME_TYPE 147
#define OGS_PFCP_EVENT_QUOTA_TYPE 148
#define OGS_PFCP_EVENT_THRESHOLD_TYPE 149
#define OGS_PFCP_SUBSEQUENT_EVENT_QUOTA_TYPE 150
#define OGS_PFCP_SUBSEQUENT_EVENT_THRESHOLD_TYPE 151
#define OGS_PFCP_TRACE_INFORMATION_TYPE 152
#define OGS_PFCP_FRAMED_ROUTE_TYPE 153
#define OGS_PFCP_FRAMED_ROUTING_TYPE 154
#define OGS_PFCP_FRAMED_IPV6_ROUTE_TYPE 155
#define OGS_PFCP_TIME_STAMP_TYPE 156
#define OGS_PFCP_AVERAGING_WINDOW_TYPE 157
#define OGS_PFCP_PAGING_POLICY_INDICATOR_TYPE 158
#define OGS_PFCP_APN_DNN_TYPE 159
#define OGS_PFCP__INTERFACE_TYPE_TYPE 160
#define OGS_PFCP_PFCPSRREQ_FLAGS_TYPE 161
#define OGS_PFCP_PFCPAUREQ_FLAGS_TYPE 162
#define OGS_PFCP_ACTIVATION_TIME_TYPE 163
#define OGS_PFCP_DEACTIVATION_TIME_TYPE 164
#define OGS_PFCP_CREATE_MAR_TYPE 165
#define OGS_PFCP__ACCESS_FORWARDING_ACTION_INFORMATION_TYPE 166
#define OGS_PFCP_NON__ACCESS_FORWARDING_ACTION_INFORMATION_TYPE 167
#define OGS_PFCP_REMOVE_MAR_TYPE 168
#define OGS_PFCP_UPDATE_MAR_TYPE 169
#define OGS_PFCP_MAR_ID_TYPE 170
#define OGS_PFCP_STEERING_FUNCTIONALITY_TYPE 171
#define OGS_PFCP_STEERING_MODE_TYPE 172
#define OGS_PFCP_WEIGHT_TYPE 173
#define OGS_PFCP_PRIORITY_TYPE 174
#define OGS_PFCP_UPDATE__ACCESS_FORWARDING_ACTION_INFORMATION_TYPE 175
#define OGS_PFCP_UPDATE_NON__ACCESS_FORWARDING_ACTION_INFORMATION_TYPE 176
#define OGS_PFCP_UE_IP_ADDRESS_POOL_IDENTITY_TYPE 177
#define OGS_PFCP_ALTERNATIVE_SMF_IP_ADDRESS_TYPE 178
#define OGS_PFCP_PACKET_REPLICATION_AND_DETECTION_CARRY_ON_INFORMATION_TYPE 179
#define OGS_PFCP_SMF_SET_ID_TYPE 180
#define OGS_PFCP_QUOTA_VALIDITY_TIME_TYPE 181
#define OGS_PFCP_NUMBER_OF_REPORTS_TYPE 182
#define OGS_PFCP_PFCP_SESSION_RETENTION_INFORMATION_WITHIN_PFCP_ASSOCIATION_SETUP_REQUEST_TYPE 183
#define OGS_PFCP_PFCPASRSP_FLAGS_TYPE 184
#define OGS_PFCP_CP_PFCP_ENTITY_IP_ADDRESS_TYPE 185
#define OGS_PFCP_PFCPSEREQ_FLAGS_TYPE 186
#define OGS_PFCP_USER_PLANE_PATH_RECOVERY_REPORT_TYPE 187
#define OGS_PFCP_IP_MULTICAST_ADDRESSING_INFO_WITHIN_PFCP_SESSION_ESTABLISHMENT_REQUEST_TYPE 188
#define OGS_PFCP_JOIN_IP_MULTICAST_INFORMATION_IE_WITHIN_USAGE_REPORT_TYPE 189
#define OGS_PFCP_LEAVE_IP_MULTICAST_INFORMATION_IE_WITHIN_USAGE_REPORT_TYPE 190
#define OGS_PFCP_IP_MULTICAST_ADDRESS_TYPE 191
#define OGS_PFCP_SOURCE_IP_ADDRESS_TYPE 192
#define OGS_PFCP_PACKET_RATE_STATUS_TYPE 193
#define OGS_PFCP_CREATE_BRIDGE_INFO_FOR_TSC_TYPE 194
#define OGS_PFCP_CREATED_BRIDGE_INFO_FOR_TSC_TYPE 195
#define OGS_PFCP_DS_TT_PORT_NUMBER_TYPE 196
#define OGS_PFCP_NW_TT_PORT_NUMBER_TYPE 197
#define OGS_PFCP_TSN_BRIDGE_ID_TYPE 198
#define OGS_PFCP_TSC_MANAGEMENT_INFORMATION_IE_WITHIN_PFCP_SESSION_MODIFICATION_REQUEST_TYPE 199
#define OGS_PFCP_TSC_MANAGEMENT_INFORMATION_IE_WITHIN_PFCP_SESSION_MODIFICATION_RESPONSE_TYPE 200
#define OGS_PFCP_TSC_MANAGEMENT_INFORMATION_IE_WITHIN_PFCP_SESSION_REPORT_REQUEST_TYPE 201
#define OGS_PFCP_PORT_MANAGEMENT_INFORMATION_CONTAINER_TYPE 202
#define OGS_PFCP_CLOCK_DRIFT_CONTROL_INFORMATION_TYPE 203
#define OGS_PFCP_REQUESTED_CLOCK_DRIFT_INFORMATION_TYPE 204
#define OGS_PFCP_CLOCK_DRIFT_REPORT_TYPE 205
#define OGS_PFCP_TSN_TIME_DOMAIN_NUMBER_TYPE 206
#define OGS_PFCP_TIME_OFFSET_THRESHOLD_TYPE 207
#define OGS_PFCP_CUMULATIVE_RATERATIO_THRESHOLD_TYPE 208
#define OGS_PFCP_TIME_OFFSET_MEASUREMENT_TYPE 209
#define OGS_PFCP_CUMULATIVE_RATERATIO_MEASUREMENT_TYPE 210
#define OGS_PFCP_REMOVE_SRR_TYPE 211
#define OGS_PFCP_CREATE_SRR_TYPE 212
#define OGS_PFCP_UPDATE_SRR_TYPE 213
#define OGS_PFCP_SESSION_REPORT_TYPE 214
#define OGS_PFCP_SRR_ID_TYPE 215
#define OGS_PFCP_ACCESS_AVAILABILITY_CONTROL_INFORMATION_TYPE 216
#define OGS_PFCP_REQUESTED_ACCESS_AVAILABILITY_INFORMATION_TYPE 217
#define OGS_PFCP_ACCESS_AVAILABILITY_REPORT_TYPE 218
#define OGS_PFCP_ACCESS_AVAILABILITY_INFORMATION_TYPE 219
#define OGS_PFCP_PROVIDE_ATSSS_CONTROL_INFORMATION_TYPE 220
#define OGS_PFCP_ATSSS_CONTROL_PARAMETERS_TYPE 221
#define OGS_PFCP_MPTCP_CONTROL_INFORMATION_TYPE 222
#define OGS_PFCP_ATSSS_LL_CONTROL_INFORMATION_TYPE 223
#define OGS_PFCP_PMF_CONTROL_INFORMATION_TYPE 224
#define OGS_PFCP_MPTCP_PARAMETERS_TYPE 225
#define OGS_PFCP_ATSSS_LL_PARAMETERS_TYPE 226
#define OGS_PFCP_PMF_PARAMETERS_TYPE 227
#define OGS_PFCP_MPTCP_ADDRESS_INFORMATION_TYPE 228
#define OGS_PFCP_UE_LINK_SPECIFIC_IP_ADDRESS_TYPE 229
#define OGS_PFCP_PMF_ADDRESS_INFORMATION_TYPE 230
#define OGS_PFCP_ATSSS_LL_INFORMATION_TYPE 231
#define OGS_PFCP_DATA_NETWORK_ACCESS_IDENTIFIER_TYPE 232
#define OGS_PFCP_UE_IP_ADDRESS_POOL_INFORMATION_TYPE 233
#define OGS_PFCP_AVERAGE_PACKET_DELAY_TYPE 234
#define OGS_PFCP_MINIMUM_PACKET_DELAY_TYPE 235
#define OGS_PFCP_MAXIMUM_PACKET_DELAY_TYPE 236
#define OGS_PFCP_QOS_REPORT_TRIGGER_TYPE 237
#define OGS_PFCP_GTP_U_PATH_QOS_CONTROL_INFORMATION_TYPE 238
#define OGS_PFCP_GTP_U_PATH_QOS_REPORT_PFCP_NODE_REPORT_REQUEST_TYPE 239
#define OGS_PFCP_QOS_INFORMATION_IN_GTP_U_PATH_QOS_REPORT_TYPE 240
#define OGS_PFCP_GTP_U_PATH_INTERFACE_TYPE_TYPE 241
#define OGS_PFCP_QOS_MONITORING_PER_QOS_FLOW_CONTROL_INFORMATION_TYPE 242
#define OGS_PFCP_REQUESTED_QOS_MONITORING_TYPE 243
#define OGS_PFCP_REPORTING_FREQUENCY_TYPE 244
#define OGS_PFCP_PACKET_DELAY_THRESHOLDS_TYPE 245
#define OGS_PFCP_MINIMUM_WAIT_TIME_TYPE 246
#define OGS_PFCP_QOS_MONITORING_REPORT_TYPE 247
#define OGS_PFCP_QOS_MONITORING_MEASUREMENT_TYPE 248
#define OGS_PFCP_MT_EDT_CONTROL_INFORMATION_TYPE 249
#define OGS_PFCP_DL_DATA_PACKETS_SIZE_TYPE 250
#define OGS_PFCP_QER_CONTROL_INDICATIONS_TYPE 251
#define OGS_PFCP_PACKET_RATE_STATUS_REPORT_TYPE 252
#define OGS_PFCP_NF_INSTANCE_ID_TYPE 253
#define OGS_PFCP_ETHERNET_CONTEXT_INFORMATION_TYPE 254
#define OGS_PFCP_REDUNDANT_TRANSMISSION_PARAMETERS_TYPE 255
#define OGS_PFCP_UPDATED_PDR_TYPE 256
#define OGS_PFCP_S_NSSAI_TYPE 257
#define OGS_PFCP_IP_VERSION_TYPE 258
#define OGS_PFCP_PFCPASREQ_FLAGS_TYPE 259
#define OGS_PFCP_DATA_STATUS_TYPE 260
#define OGS_PFCP_PROVIDE_RDS_CONFIGURATION_INFORMATION_TYPE 261
#define OGS_PFCP_RDS_CONFIGURATION_INFORMATION_TYPE 262
#define OGS_PFCP_QUERY_PACKET_RATE_STATUS_IE_WITHIN_PFCP_SESSION_MODIFICATION_REQUEST_TYPE 263
#define OGS_PFCP_PACKET_RATE_STATUS_REPORT_IE_WITHIN_PFCP_SESSION_MODIFICATION_RESPONSE_TYPE 264
#define OGS_PFCP_MPTCP_APPLICABLE_INDICATION_TYPE 265
#define OGS_PFCP_BRIDGE_MANAGEMENT_INFORMATION_CONTAINER_TYPE 266
#define OGS_PFCP_UE_IP_ADDRESS_USAGE_INFORMATION_TYPE 267
#define OGS_PFCP_NUMBER_OF_UE_IP_ADDRESSES_TYPE 268
#define OGS_PFCP_VALIDITY_TIMER_TYPE 269
#define OGS_PFCP_REDUNDANT_TRANSMISSION_FORWARDING_PARAMETERS_TYPE 270
#define OGS_PFCP_TRANSPORT_DELAY_REPORTING_TYPE 271

    /* Information Element TLV Descriptor */
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_cause;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_source_interface;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_f_teid;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_network_instance;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_sdf_filter;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_application_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_gate_status;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mbr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_gbr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qer_correlation_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_precedence;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_transport_level_marking;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_volume_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_monitoring_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_volume_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_time_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_inactivity_detection_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_reporting_triggers;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_redirect_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_report_type;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_offending_ie;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_forwarding_policy;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_destination_interface;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_up_function_features;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_apply_action;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_downlink_data_service_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_downlink_data_notification_delay;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_dl_buffering_duration;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_dl_buffering_suggested_packet_count;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpsmreq_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpsrrsp_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_sequence_number;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_metric;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_timer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pdr_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_f_seid;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_node_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfd_contents;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_measurement_method;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_usage_report_trigger;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_measurement_period;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_fq_csid;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_volume_measurement;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_duration_measurement;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_of_first_packet;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_of_last_packet;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_quota_holding_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_dropped_dl_traffic_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_volume_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_start_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_end_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_urr_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_linked_urr_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_outer_header_creation;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_bar_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_cp_function_features;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_usage_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_application_instance_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_flow_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ue_ip_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_rate;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_outer_header_removal;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_recovery_time_stamp;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_dl_flow_level_marking;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_header_enrichment;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_measurement_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_node_report_type;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remote_gtp_u_peer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ur_seqn;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_activate_predefined_rules;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_deactivate_predefined_rules;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_far_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qer_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_oci_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcp_association_release_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_graceful_release_period;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pdn_type;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_failed_rule_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_quota_mechanism;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_user_plane_ip_resource_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_user_plane_inactivity_timer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_aggregated_urrs;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_multiplier;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_aggregated_urr_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_volume_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_time_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_rqi;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qfi;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_query_urr_reference;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_additional_usage_reports_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_traffic_endpoint;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_traffic_endpoint_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mac_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_c_tag;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_s_tag;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethertype;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_proxying;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_filter_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_filter_properties;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_suggested_buffering_packets_count;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_user_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_pdu_session_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mac_addresses_detected;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mac_addresses_removed;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_inactivity_timer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_additional_monitoring_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_event_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_event_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_event_quota;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_subsequent_event_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_trace_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_framed_route;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_framed_routing;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_framed_ipv6_route;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_stamp;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_averaging_window;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_paging_policy_indicator;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_apn_dnn;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc__interface_type;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpsrreq_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpaureq_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_activation_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_deactivation_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mar_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_steering_functionality;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_steering_mode;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_weight;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_priority;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ue_ip_address_pool_identity;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_alternative_smf_ip_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_replication_and_detection_carry_on_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_smf_set_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_quota_validity_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_number_of_reports;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpasrsp_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_cp_pfcp_entity_ip_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpsereq_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ip_multicast_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_source_ip_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_rate_status;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_bridge_info_for_tsc;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ds_tt_port_number;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_nw_tt_port_number;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_tsn_bridge_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_port_management_information_container;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_requested_clock_drift_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_tsn_time_domain_number;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_offset_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_cumulative_rateratio_threshold;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_time_offset_measurement;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_cumulative_rateratio_measurement;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_srr_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_access_availability_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_requested_access_availability_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_access_availability_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mptcp_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_atsss_ll_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pmf_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mptcp_address_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ue_link_specific_ip_address;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pmf_address_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_atsss_ll_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_data_network_access_identifier;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_average_packet_delay;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_minimum_packet_delay;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_maximum_packet_delay;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qos_report_trigger;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_gtp_u_path_qos_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_gtp_u_path_interface_type;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qos_monitoring_per_qos_flow_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_requested_qos_monitoring;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_reporting_frequency;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_delay_thresholds;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_minimum_wait_time;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qos_monitoring_measurement;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mt_edt_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_dl_data_packets_size;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qer_control_indications;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_nf_instance_id;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_s_nssai;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ip_version;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcpasreq_flags;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_data_status;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_rds_configuration_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mptcp_applicable_indication;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_bridge_management_information_container;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_number_of_ue_ip_addresses;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_validity_timer;

    /* Group Information Element TLV Descriptor */
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_packet_filter;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_redundant_transmission_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ip_multicast_addressing_info_within_pfcp_session_establishment_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pdi;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_transport_delay_reporting;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_pdr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_forwarding_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_duplicating_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_redundant_transmission_forwarding_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_far;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_forwarding_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_duplicating_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_far;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfd_context;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_application_id_s_pfds;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_traffic_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc__access_forwarding_action_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_non__access_forwarding_action_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update__access_forwarding_action_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_non__access_forwarding_action_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_access_availability_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qos_monitoring_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_mptcp_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_atsss_ll_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pmf_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_join_ip_multicast_information_ie_within_usage_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_leave_ip_multicast_information_ie_within_usage_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_urr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_qer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_created_pdr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_pdr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_bar_pfcp_session_report_response;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_urr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_qer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_pdr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_far;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_urr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_qer;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_load_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_overload_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_application_detection_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_query_urr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_usage_report_session_modification_response;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_usage_report_session_deletion_response;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_usage_report_session_report_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_downlink_data_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_bar;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_bar_session_modification_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_bar;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_error_indication_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_user_plane_path_failure_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_traffic_endpoint;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_created_traffic_endpoint;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_traffic_endpoint;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_mar;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_mar;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_mar;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_pfcp_session_retention_information_within_pfcp_association_setup_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_user_plane_path_recovery_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_created_bridge_info_for_tsc;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_tsc_management_information_ie_within_pfcp_session_modification_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_tsc_management_information_ie_within_pfcp_session_modification_response;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_tsc_management_information_ie_within_pfcp_session_report_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_clock_drift_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_clock_drift_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_remove_srr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_create_srr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_update_srr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_session_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_provide_atsss_control_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_atsss_control_parameters;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ue_ip_address_pool_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_gtp_u_path_qos_report_pfcp_node_report_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_qos_information_in_gtp_u_path_qos_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_rate_status_report;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ethernet_context_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_updated_pdr;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_provide_rds_configuration_information;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_query_packet_rate_status_ie_within_pfcp_session_modification_request;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_packet_rate_status_report_ie_within_pfcp_session_modification_response;
    extern ogs_tlv_desc_t ogs_pfcp_tlv_desc_ue_ip_address_usage_information;

    /* Message Descriptor */
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_heartbeat_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_heartbeat_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_pfd_management_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_pfd_management_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_setup_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_setup_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_update_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_update_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_release_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_association_release_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_version_not_supported_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_node_report_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_node_report_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_set_deletion_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_set_deletion_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_establishment_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_establishment_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_modification_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_modification_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_deletion_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_deletion_response;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_report_request;
extern ogs_tlv_desc_t ogs_pfcp_msg_desc_pfcp_session_report_response;

/* Structure for Information Element */
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_cause_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_source_interface_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_f_teid_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_network_instance_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_sdf_filter_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_application_id_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_gate_status_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mbr_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_gbr_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_qer_correlation_id_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_precedence_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_transport_level_marking_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_volume_threshold_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_time_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_monitoring_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_volume_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_time_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_inactivity_detection_time_t;
typedef ogs_tlv_uint24_t ogs_pfcp_tlv_reporting_triggers_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_redirect_information_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_report_type_t;
typedef ogs_tlv_uint16_t ogs_pfcp_tlv_offending_ie_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_forwarding_policy_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_destination_interface_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_up_function_features_t;
typedef ogs_tlv_uint16_t ogs_pfcp_tlv_apply_action_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_downlink_data_service_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_downlink_data_notification_delay_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_dl_buffering_duration_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_dl_buffering_suggested_packet_count_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_pfcpsmreq_flags_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_pfcpsrrsp_flags_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_sequence_number_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_metric_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_timer_t;
typedef ogs_tlv_uint16_t ogs_pfcp_tlv_pdr_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_f_seid_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_node_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pfd_contents_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_measurement_method_t;
typedef ogs_tlv_uint24_t ogs_pfcp_tlv_usage_report_trigger_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_measurement_period_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_fq_csid_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_volume_measurement_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_duration_measurement_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_time_of_first_packet_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_time_of_last_packet_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_quota_holding_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_dropped_dl_traffic_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_volume_quota_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_time_quota_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_start_time_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_end_time_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_urr_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_linked_urr_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_outer_header_creation_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_bar_id_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_cp_function_features_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_usage_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_application_instance_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_flow_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ue_ip_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_packet_rate_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_outer_header_removal_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_recovery_time_stamp_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_dl_flow_level_marking_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_header_enrichment_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_measurement_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_node_report_type_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_remote_gtp_u_peer_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_ur_seqn_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_activate_predefined_rules_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_deactivate_predefined_rules_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_far_id_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_qer_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_oci_flags_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pfcp_association_release_request_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_graceful_release_period_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_pdn_type_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_failed_rule_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_time_quota_mechanism_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_user_plane_ip_resource_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_user_plane_inactivity_timer_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_aggregated_urrs_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_multiplier_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_aggregated_urr_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_volume_quota_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_time_quota_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_rqi_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_qfi_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_query_urr_reference_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_additional_usage_reports_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_update_traffic_endpoint_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_traffic_endpoint_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mac_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_c_tag_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_s_tag_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ethertype_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_proxying_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ethernet_filter_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ethernet_filter_properties_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_suggested_buffering_packets_count_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_user_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ethernet_pdu_session_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mac_addresses_detected_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mac_addresses_removed_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ethernet_inactivity_timer_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_additional_monitoring_time_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_event_quota_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_event_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_event_quota_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_subsequent_event_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_trace_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_framed_route_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_framed_routing_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_framed_ipv6_route_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_time_stamp_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_averaging_window_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_paging_policy_indicator_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_apn_dnn_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv__interface_type_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_pfcpsrreq_flags_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_pfcpaureq_flags_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_activation_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_deactivation_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mar_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_steering_functionality_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_steering_mode_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_weight_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_priority_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ue_ip_address_pool_identity_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_alternative_smf_ip_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_packet_replication_and_detection_carry_on_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_smf_set_id_t;
typedef ogs_tlv_uint32_t ogs_pfcp_tlv_quota_validity_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_number_of_reports_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pfcpasrsp_flags_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_cp_pfcp_entity_ip_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pfcpsereq_flags_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ip_multicast_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_source_ip_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_packet_rate_status_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_create_bridge_info_for_tsc_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ds_tt_port_number_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_nw_tt_port_number_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_tsn_bridge_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_port_management_information_container_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_requested_clock_drift_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_tsn_time_domain_number_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_time_offset_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_cumulative_rateratio_threshold_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_time_offset_measurement_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_cumulative_rateratio_measurement_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_srr_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_access_availability_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_requested_access_availability_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_access_availability_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mptcp_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_atsss_ll_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pmf_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mptcp_address_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ue_link_specific_ip_address_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pmf_address_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_atsss_ll_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_data_network_access_identifier_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_average_packet_delay_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_minimum_packet_delay_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_maximum_packet_delay_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_qos_report_trigger_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_gtp_u_path_qos_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_gtp_u_path_interface_type_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_qos_monitoring_per_qos_flow_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_requested_qos_monitoring_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_reporting_frequency_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_packet_delay_thresholds_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_minimum_wait_time_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_qos_monitoring_measurement_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mt_edt_control_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_dl_data_packets_size_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_qer_control_indications_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_nf_instance_id_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_s_nssai_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_ip_version_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_pfcpasreq_flags_t;
typedef ogs_tlv_uint8_t ogs_pfcp_tlv_data_status_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_rds_configuration_information_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_mptcp_applicable_indication_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_bridge_management_information_container_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_number_of_ue_ip_addresses_t;
typedef ogs_tlv_octet_t ogs_pfcp_tlv_validity_timer_t;

/* Structure for Group Information Element */
typedef struct ogs_pfcp_tlv_ethernet_packet_filter_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ethernet_filter_id_t ethernet_filter_id;
    ogs_pfcp_tlv_ethernet_filter_properties_t ethernet_filter_properties;
    ogs_pfcp_tlv_mac_address_t mac_address;
    ogs_pfcp_tlv_ethertype_t ethertype;
    ogs_pfcp_tlv_c_tag_t c_tag;
    ogs_pfcp_tlv_s_tag_t s_tag;
    ogs_pfcp_tlv_sdf_filter_t sdf_filter[8];
} ogs_pfcp_tlv_ethernet_packet_filter_t;

typedef struct ogs_pfcp_tlv_redundant_transmission_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_f_teid_t local_f_teid_for_redundant_transmission;
    ogs_pfcp_tlv_network_instance_t network_instance_for_redundant_transmission;
} ogs_pfcp_tlv_redundant_transmission_parameters_t;

typedef struct ogs_pfcp_tlv_ip_multicast_addressing_info_within_pfcp_session_establishment_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ip_multicast_address_t ip_multicast_address;
    ogs_pfcp_tlv_source_ip_address_t source_ip_address;
} ogs_pfcp_tlv_ip_multicast_addressing_info_within_pfcp_session_establishment_request_t;

typedef struct ogs_pfcp_tlv_pdi_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_source_interface_t source_interface;
    ogs_pfcp_tlv_f_teid_t local_f_teid;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_redundant_transmission_parameters_t redundant_transmission_detection_parameters;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
    ogs_pfcp_tlv_traffic_endpoint_id_t traffic_endpoint_id;
    ogs_pfcp_tlv_sdf_filter_t sdf_filter[8];
    ogs_pfcp_tlv_application_id_t application_id;
    ogs_pfcp_tlv_ethernet_pdu_session_information_t ethernet_pdu_session_information;
    ogs_pfcp_tlv_ethernet_packet_filter_t ethernet_packet_filter;
    ogs_pfcp_tlv_qfi_t qfi;
    ogs_pfcp_tlv_framed_route_t framed_route;
    ogs_pfcp_tlv_framed_routing_t framed_routing;
    ogs_pfcp_tlv_framed_ipv6_route_t framed_ipv6_route;
    ogs_pfcp_tlv__interface_type_t source_interface_type;
    ogs_pfcp_tlv_ip_multicast_addressing_info_within_pfcp_session_establishment_request_t ip_multicast_addressing_info;
} ogs_pfcp_tlv_pdi_t;

typedef struct ogs_pfcp_tlv_transport_delay_reporting_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_remote_gtp_u_peer_t preceding_ul_gtp_u_peer;
    ogs_pfcp_tlv_transport_level_marking_t dscp;
} ogs_pfcp_tlv_transport_delay_reporting_t;

typedef struct ogs_pfcp_tlv_create_pdr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
    ogs_pfcp_tlv_precedence_t precedence;
    ogs_pfcp_tlv_pdi_t pdi;
    ogs_pfcp_tlv_outer_header_removal_t outer_header_removal;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_urr_id_t urr_id[8];
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_activate_predefined_rules_t activate_predefined_rules;
    ogs_pfcp_tlv_activation_time_t activation_time;
    ogs_pfcp_tlv_deactivation_time_t deactivation_time;
    ogs_pfcp_tlv_mar_id_t mar_id;
    ogs_pfcp_tlv_packet_replication_and_detection_carry_on_information_t packet_replication_and_detection_carry_on_information;
    ogs_pfcp_tlv_ip_multicast_addressing_info_within_pfcp_session_establishment_request_t ip_multicast_addressing_info;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_identity;
    ogs_pfcp_tlv_mptcp_applicable_indication_t mptcp_applicable_indication;
    ogs_pfcp_tlv_transport_delay_reporting_t transport_delay_reporting;
} ogs_pfcp_tlv_create_pdr_t;

typedef struct ogs_pfcp_tlv_forwarding_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_destination_interface_t destination_interface;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_redirect_information_t redirect_information;
    ogs_pfcp_tlv_outer_header_creation_t outer_header_creation;
    ogs_pfcp_tlv_transport_level_marking_t transport_level_marking;
    ogs_pfcp_tlv_forwarding_policy_t forwarding_policy;
    ogs_pfcp_tlv_header_enrichment_t header_enrichment;
    ogs_pfcp_tlv_traffic_endpoint_id_t linked_traffic_endpoint_id;
    ogs_pfcp_tlv_proxying_t proxying;
    ogs_pfcp_tlv__interface_type_t destination_interface_type;
    ogs_pfcp_tlv_data_network_access_identifier_t data_network_access_identifier;
} ogs_pfcp_tlv_forwarding_parameters_t;

typedef struct ogs_pfcp_tlv_duplicating_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_destination_interface_t destination_interface;
    ogs_pfcp_tlv_outer_header_creation_t outer_header_creation;
    ogs_pfcp_tlv_transport_level_marking_t transport_level_marking;
    ogs_pfcp_tlv_forwarding_policy_t forwarding_policy;
} ogs_pfcp_tlv_duplicating_parameters_t;

typedef struct ogs_pfcp_tlv_redundant_transmission_forwarding_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_outer_header_creation_t outer_header_creation;
    ogs_pfcp_tlv_network_instance_t network_instance_for_redundant_transmission;
} ogs_pfcp_tlv_redundant_transmission_forwarding_parameters_t;

typedef struct ogs_pfcp_tlv_create_far_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_apply_action_t apply_action;
    ogs_pfcp_tlv_forwarding_parameters_t forwarding_parameters;
    ogs_pfcp_tlv_duplicating_parameters_t duplicating_parameters;
    ogs_pfcp_tlv_bar_id_t bar_id;
    ogs_pfcp_tlv_redundant_transmission_forwarding_parameters_t redundant_transmission_forwarding_parameters;
} ogs_pfcp_tlv_create_far_t;

typedef struct ogs_pfcp_tlv_update_forwarding_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_destination_interface_t destination_interface;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_redirect_information_t redirect_information;
    ogs_pfcp_tlv_outer_header_creation_t outer_header_creation;
    ogs_pfcp_tlv_transport_level_marking_t transport_level_marking;
    ogs_pfcp_tlv_forwarding_policy_t forwarding_policy;
    ogs_pfcp_tlv_header_enrichment_t header_enrichment;
    ogs_pfcp_tlv_pfcpsmreq_flags_t pfcpsmreq_flags;
    ogs_pfcp_tlv_traffic_endpoint_id_t linked_traffic_endpoint_id;
    ogs_pfcp_tlv__interface_type_t destination_interface_type;
    ogs_pfcp_tlv_data_network_access_identifier_t data_network_access_identifier;
} ogs_pfcp_tlv_update_forwarding_parameters_t;

typedef struct ogs_pfcp_tlv_update_duplicating_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_destination_interface_t destination_interface;
    ogs_pfcp_tlv_outer_header_creation_t outer_header_creation;
    ogs_pfcp_tlv_transport_level_marking_t transport_level_marking;
    ogs_pfcp_tlv_forwarding_policy_t forwarding_policy;
} ogs_pfcp_tlv_update_duplicating_parameters_t;

typedef struct ogs_pfcp_tlv_update_far_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_apply_action_t apply_action;
    ogs_pfcp_tlv_update_forwarding_parameters_t update_forwarding_parameters;
    ogs_pfcp_tlv_update_duplicating_parameters_t update_duplicating_parameters;
    ogs_pfcp_tlv_redundant_transmission_forwarding_parameters_t redundant_transmission_forwarding_parameters;
    ogs_pfcp_tlv_bar_id_t bar_id;
} ogs_pfcp_tlv_update_far_t;

typedef struct ogs_pfcp_tlv_pfd_context_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pfd_contents_t pfd_contents;
} ogs_pfcp_tlv_pfd_context_t;

typedef struct ogs_pfcp_tlv_application_id_s_pfds_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_application_id_t application_id;
    ogs_pfcp_tlv_pfd_context_t pfd_context;
} ogs_pfcp_tlv_application_id_s_pfds_t;

typedef struct ogs_pfcp_tlv_ethernet_traffic_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mac_addresses_detected_t mac_addresses_detected;
    ogs_pfcp_tlv_mac_addresses_removed_t mac_addresses_removed;
} ogs_pfcp_tlv_ethernet_traffic_information_t;

typedef struct ogs_pfcp_tlv__access_forwarding_action_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_weight_t weight;
    ogs_pfcp_tlv_priority_t priority;
    ogs_pfcp_tlv_urr_id_t urr_id[8];
} ogs_pfcp_tlv__access_forwarding_action_information_t;

typedef struct ogs_pfcp_tlv_non__access_forwarding_action_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_weight_t weight;
    ogs_pfcp_tlv_priority_t priority;
    ogs_pfcp_tlv_urr_id_t urr_id[8];
} ogs_pfcp_tlv_non__access_forwarding_action_information_t;

typedef struct ogs_pfcp_tlv_update__access_forwarding_action_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_weight_t weight;
    ogs_pfcp_tlv_priority_t priority;
    ogs_pfcp_tlv_urr_id_t urr_id;
} ogs_pfcp_tlv_update__access_forwarding_action_information_t;

typedef struct ogs_pfcp_tlv_update_non__access_forwarding_action_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_weight_t weight;
    ogs_pfcp_tlv_priority_t priority;
    ogs_pfcp_tlv_urr_id_t urr_id;
} ogs_pfcp_tlv_update_non__access_forwarding_action_information_t;

typedef struct ogs_pfcp_tlv_access_availability_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_access_availability_information_t access_availability_information;
} ogs_pfcp_tlv_access_availability_report_t;

typedef struct ogs_pfcp_tlv_qos_monitoring_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qfi_t qfi;
    ogs_pfcp_tlv_qos_monitoring_measurement_t qos_monitoring_measurement;
    ogs_pfcp_tlv_time_stamp_t time_stamp;
    ogs_pfcp_tlv_start_time_t start_time;
} ogs_pfcp_tlv_qos_monitoring_report_t;

typedef struct ogs_pfcp_tlv_mptcp_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mptcp_address_information_t mptcp_address_information;
    ogs_pfcp_tlv_ue_link_specific_ip_address_t ue_link_specific_ip_address;
} ogs_pfcp_tlv_mptcp_parameters_t;

typedef struct ogs_pfcp_tlv_atsss_ll_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_atsss_ll_information_t atsss_ll_information;
} ogs_pfcp_tlv_atsss_ll_parameters_t;

typedef struct ogs_pfcp_tlv_pmf_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pmf_address_information_t pmf_address_information;
} ogs_pfcp_tlv_pmf_parameters_t;

typedef struct ogs_pfcp_tlv_join_ip_multicast_information_ie_within_usage_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ip_multicast_address_t ip_multicast_address;
    ogs_pfcp_tlv_source_ip_address_t source_ip_address;
} ogs_pfcp_tlv_join_ip_multicast_information_ie_within_usage_report_t;

typedef struct ogs_pfcp_tlv_leave_ip_multicast_information_ie_within_usage_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ip_multicast_address_t ip_multicast_address;
    ogs_pfcp_tlv_source_ip_address_t source_ip_address;
} ogs_pfcp_tlv_leave_ip_multicast_information_ie_within_usage_report_t;

typedef struct ogs_pfcp_tlv_create_urr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_measurement_method_t measurement_method;
    ogs_pfcp_tlv_reporting_triggers_t reporting_triggers;
    ogs_pfcp_tlv_measurement_period_t measurement_period;
    ogs_pfcp_tlv_volume_threshold_t volume_threshold;
    ogs_pfcp_tlv_volume_quota_t volume_quota;
    ogs_pfcp_tlv_event_threshold_t event_threshold;
    ogs_pfcp_tlv_event_quota_t event_quota;
    ogs_pfcp_tlv_time_threshold_t time_threshold;
    ogs_pfcp_tlv_time_quota_t time_quota;
    ogs_pfcp_tlv_quota_holding_time_t quota_holding_time;
    ogs_pfcp_tlv_dropped_dl_traffic_threshold_t dropped_dl_traffic_threshold;
    ogs_pfcp_tlv_quota_validity_time_t quota_validity_time;
    ogs_pfcp_tlv_monitoring_time_t monitoring_time;
    ogs_pfcp_tlv_subsequent_volume_threshold_t subsequent_volume_threshold;
    ogs_pfcp_tlv_subsequent_time_threshold_t subsequent_time_threshold;
    ogs_pfcp_tlv_subsequent_volume_quota_t subsequent_volume_quota;
    ogs_pfcp_tlv_subsequent_time_quota_t subsequent_time_quota;
    ogs_pfcp_tlv_subsequent_event_threshold_t subsequent_event_threshold;
    ogs_pfcp_tlv_subsequent_event_quota_t subsequent_event_quota;
    ogs_pfcp_tlv_inactivity_detection_time_t inactivity_detection_time;
    ogs_pfcp_tlv_linked_urr_id_t linked_urr_id;
    ogs_pfcp_tlv_measurement_information_t measurement_information;
    ogs_pfcp_tlv_time_quota_mechanism_t time_quota_mechanism;
    ogs_pfcp_tlv_aggregated_urrs_t aggregated_urrs;
    ogs_pfcp_tlv_far_id_t far_id_for_quota_action;
    ogs_pfcp_tlv_ethernet_inactivity_timer_t ethernet_inactivity_timer;
    ogs_pfcp_tlv_additional_monitoring_time_t additional_monitoring_time;
    ogs_pfcp_tlv_number_of_reports_t number_of_reports;
} ogs_pfcp_tlv_create_urr_t;

typedef struct ogs_pfcp_tlv_create_qer_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_qer_correlation_id_t qer_correlation_id;
    ogs_pfcp_tlv_gate_status_t gate_status;
    ogs_pfcp_tlv_mbr_t maximum_bitrate;
    ogs_pfcp_tlv_gbr_t guaranteed_bitrate;
    ogs_pfcp_tlv_packet_rate_t packet_rate;
    ogs_pfcp_tlv_packet_rate_status_t packet_rate_status;
    ogs_pfcp_tlv_dl_flow_level_marking_t dl_flow_level_marking;
    ogs_pfcp_tlv_qfi_t qos_flow_identifier;
    ogs_pfcp_tlv_rqi_t reflective_qos;
    ogs_pfcp_tlv_paging_policy_indicator_t paging_policy_indicator;
    ogs_pfcp_tlv_averaging_window_t averaging_window;
    ogs_pfcp_tlv_qer_control_indications_t qer_control_indications;
} ogs_pfcp_tlv_create_qer_t;

typedef struct ogs_pfcp_tlv_created_pdr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
    ogs_pfcp_tlv_f_teid_t local_f_teid;
    ogs_pfcp_tlv_f_teid_t local_f_teid_for_redundant_transmission;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
} ogs_pfcp_tlv_created_pdr_t;

typedef struct ogs_pfcp_tlv_update_pdr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
    ogs_pfcp_tlv_outer_header_removal_t outer_header_removal;
    ogs_pfcp_tlv_precedence_t precedence;
    ogs_pfcp_tlv_pdi_t pdi;
    ogs_pfcp_tlv_far_id_t far_id;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_activate_predefined_rules_t activate_predefined_rules;
    ogs_pfcp_tlv_deactivate_predefined_rules_t deactivate_predefined_rules;
    ogs_pfcp_tlv_activation_time_t activation_time;
    ogs_pfcp_tlv_deactivation_time_t deactivation_time;
    ogs_pfcp_tlv_ip_multicast_addressing_info_within_pfcp_session_establishment_request_t ip_multicast_addressing_info;
    ogs_pfcp_tlv_transport_delay_reporting_t transport_delay_reporting;
} ogs_pfcp_tlv_update_pdr_t;

typedef struct ogs_pfcp_tlv_update_bar_pfcp_session_report_response_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_bar_id_t bar_id;
    ogs_pfcp_tlv_downlink_data_notification_delay_t downlink_data_notification_delay;
    ogs_pfcp_tlv_dl_buffering_duration_t dl_buffering_duration;
    ogs_pfcp_tlv_dl_buffering_suggested_packet_count_t dl_buffering_suggested_packet_count;
    ogs_pfcp_tlv_suggested_buffering_packets_count_t suggested_buffering_packets_count;
} ogs_pfcp_tlv_update_bar_pfcp_session_report_response_t;

typedef struct ogs_pfcp_tlv_update_urr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_measurement_method_t measurement_method;
    ogs_pfcp_tlv_reporting_triggers_t reporting_triggers;
    ogs_pfcp_tlv_measurement_period_t measurement_period;
    ogs_pfcp_tlv_volume_threshold_t volume_threshold;
    ogs_pfcp_tlv_volume_quota_t volume_quota;
    ogs_pfcp_tlv_time_threshold_t time_threshold;
    ogs_pfcp_tlv_time_quota_t time_quota;
    ogs_pfcp_tlv_event_threshold_t event_threshold;
    ogs_pfcp_tlv_event_quota_t event_quota;
    ogs_pfcp_tlv_quota_holding_time_t quota_holding_time;
    ogs_pfcp_tlv_dropped_dl_traffic_threshold_t dropped_dl_traffic_threshold;
    ogs_pfcp_tlv_quota_validity_time_t quota_validity_time;
    ogs_pfcp_tlv_monitoring_time_t monitoring_time;
    ogs_pfcp_tlv_subsequent_volume_threshold_t subsequent_volume_threshold;
    ogs_pfcp_tlv_subsequent_time_threshold_t subsequent_time_threshold;
    ogs_pfcp_tlv_subsequent_volume_quota_t subsequent_volume_quota;
    ogs_pfcp_tlv_subsequent_time_quota_t subsequent_time_quota;
    ogs_pfcp_tlv_subsequent_event_threshold_t subsequent_event_threshold;
    ogs_pfcp_tlv_subsequent_event_quota_t subsequent_event_quota;
    ogs_pfcp_tlv_inactivity_detection_time_t inactivity_detection_time;
    ogs_pfcp_tlv_linked_urr_id_t linked_urr_id;
    ogs_pfcp_tlv_measurement_information_t measurement_information;
    ogs_pfcp_tlv_time_quota_mechanism_t time_quota_mechanism;
    ogs_pfcp_tlv_aggregated_urrs_t aggregated_urrs;
    ogs_pfcp_tlv_far_id_t far_id_for_quota_action;
    ogs_pfcp_tlv_ethernet_inactivity_timer_t ethernet_inactivity_timer;
    ogs_pfcp_tlv_additional_monitoring_time_t additional_monitoring_time;
    ogs_pfcp_tlv_number_of_reports_t number_of_reports;
} ogs_pfcp_tlv_update_urr_t;

typedef struct ogs_pfcp_tlv_update_qer_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_qer_correlation_id_t qer_correlation_id;
    ogs_pfcp_tlv_gate_status_t gate_status;
    ogs_pfcp_tlv_mbr_t maximum_bitrate;
    ogs_pfcp_tlv_gbr_t guaranteed_bitrate;
    ogs_pfcp_tlv_packet_rate_t packet_rate;
    ogs_pfcp_tlv_dl_flow_level_marking_t dl_flow_level_marking;
    ogs_pfcp_tlv_qfi_t qos_flow_identifier;
    ogs_pfcp_tlv_rqi_t reflective_qos;
    ogs_pfcp_tlv_paging_policy_indicator_t paging_policy_indicator;
    ogs_pfcp_tlv_averaging_window_t averaging_window;
    ogs_pfcp_tlv_qer_control_indications_t qer_control_indications;
} ogs_pfcp_tlv_update_qer_t;

typedef struct ogs_pfcp_tlv_remove_pdr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
} ogs_pfcp_tlv_remove_pdr_t;

typedef struct ogs_pfcp_tlv_remove_far_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_far_id_t far_id;
} ogs_pfcp_tlv_remove_far_t;

typedef struct ogs_pfcp_tlv_remove_urr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
} ogs_pfcp_tlv_remove_urr_t;

typedef struct ogs_pfcp_tlv_remove_qer_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
} ogs_pfcp_tlv_remove_qer_t;

typedef struct ogs_pfcp_tlv_load_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_sequence_number_t load_control_sequence_number;
    ogs_pfcp_tlv_metric_t load_metric;
} ogs_pfcp_tlv_load_control_information_t;

typedef struct ogs_pfcp_tlv_overload_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_sequence_number_t overload_control_sequence_number;
    ogs_pfcp_tlv_metric_t overload_reduction_metric;
    ogs_pfcp_tlv_timer_t period_of_validity;
    ogs_pfcp_tlv_oci_flags_t overload_control_information_flags;
} ogs_pfcp_tlv_overload_control_information_t;

typedef struct ogs_pfcp_tlv_application_detection_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_application_id_t application_id;
    ogs_pfcp_tlv_application_instance_id_t application_instance_id;
    ogs_pfcp_tlv_flow_information_t flow_information;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
} ogs_pfcp_tlv_application_detection_information_t;

typedef struct ogs_pfcp_tlv_query_urr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
} ogs_pfcp_tlv_query_urr_t;

typedef struct ogs_pfcp_tlv_usage_report_session_modification_response_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_ur_seqn_t ur_seqn;
    ogs_pfcp_tlv_usage_report_trigger_t usage_report_trigger;
    ogs_pfcp_tlv_start_time_t start_time;
    ogs_pfcp_tlv_end_time_t end_time;
    ogs_pfcp_tlv_volume_measurement_t volume_measurement;
    ogs_pfcp_tlv_duration_measurement_t duration_measurement;
    ogs_pfcp_tlv_time_of_first_packet_t time_of_first_packet;
    ogs_pfcp_tlv_time_of_last_packet_t time_of_last_packet;
    ogs_pfcp_tlv_usage_information_t usage_information;
    ogs_pfcp_tlv_query_urr_reference_t query_urr_reference;
    ogs_pfcp_tlv_ethernet_traffic_information_t ethernet_traffic_information;
} ogs_pfcp_tlv_usage_report_session_modification_response_t;

typedef struct ogs_pfcp_tlv_usage_report_session_deletion_response_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_ur_seqn_t ur_seqn;
    ogs_pfcp_tlv_usage_report_trigger_t usage_report_trigger;
    ogs_pfcp_tlv_start_time_t start_time;
    ogs_pfcp_tlv_end_time_t end_time;
    ogs_pfcp_tlv_volume_measurement_t volume_measurement;
    ogs_pfcp_tlv_duration_measurement_t duration_measurement;
    ogs_pfcp_tlv_time_of_first_packet_t time_of_first_packet;
    ogs_pfcp_tlv_time_of_last_packet_t time_of_last_packet;
    ogs_pfcp_tlv_usage_information_t usage_information;
    ogs_pfcp_tlv_ethernet_traffic_information_t ethernet_traffic_information;
} ogs_pfcp_tlv_usage_report_session_deletion_response_t;

typedef struct ogs_pfcp_tlv_usage_report_session_report_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_urr_id_t urr_id;
    ogs_pfcp_tlv_ur_seqn_t ur_seqn;
    ogs_pfcp_tlv_usage_report_trigger_t usage_report_trigger;
    ogs_pfcp_tlv_start_time_t start_time;
    ogs_pfcp_tlv_end_time_t end_time;
    ogs_pfcp_tlv_volume_measurement_t volume_measurement;
    ogs_pfcp_tlv_duration_measurement_t duration_measurement;
    ogs_pfcp_tlv_application_detection_information_t application_detection_information;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_time_of_first_packet_t time_of_first_packet;
    ogs_pfcp_tlv_time_of_last_packet_t time_of_last_packet;
    ogs_pfcp_tlv_usage_information_t usage_information;
    ogs_pfcp_tlv_query_urr_reference_t query_urr_reference;
    ogs_pfcp_tlv_time_stamp_t event_time_stamp;
    ogs_pfcp_tlv_ethernet_traffic_information_t ethernet_traffic_information;
    ogs_pfcp_tlv_join_ip_multicast_information_ie_within_usage_report_t join_ip_muticast_information;
    ogs_pfcp_tlv_leave_ip_multicast_information_ie_within_usage_report_t leave_ip_muticast_information;
} ogs_pfcp_tlv_usage_report_session_report_request_t;

typedef struct ogs_pfcp_tlv_downlink_data_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
    ogs_pfcp_tlv_downlink_data_service_information_t downlink_data_service_information;
    ogs_pfcp_tlv_dl_data_packets_size_t dl_data_packets_size;
    ogs_pfcp_tlv_data_status_t dl_data_status;
} ogs_pfcp_tlv_downlink_data_report_t;

typedef struct ogs_pfcp_tlv_create_bar_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_bar_id_t bar_id;
    ogs_pfcp_tlv_downlink_data_notification_delay_t downlink_data_notification_delay;
    ogs_pfcp_tlv_suggested_buffering_packets_count_t suggested_buffering_packets_count;
    ogs_pfcp_tlv_mt_edt_control_information_t mt_edt_control_information;
} ogs_pfcp_tlv_create_bar_t;

typedef struct ogs_pfcp_tlv_update_bar_session_modification_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_bar_id_t bar_id;
    ogs_pfcp_tlv_downlink_data_notification_delay_t downlink_data_notification_delay;
    ogs_pfcp_tlv_suggested_buffering_packets_count_t suggested_buffering_packets_count;
    ogs_pfcp_tlv_mt_edt_control_information_t mt_edt_control_information;
} ogs_pfcp_tlv_update_bar_session_modification_request_t;

typedef struct ogs_pfcp_tlv_remove_bar_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_bar_id_t bar_id;
} ogs_pfcp_tlv_remove_bar_t;

typedef struct ogs_pfcp_tlv_error_indication_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_f_teid_t remote_f_teid;
} ogs_pfcp_tlv_error_indication_report_t;

typedef struct ogs_pfcp_tlv_user_plane_path_failure_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_remote_gtp_u_peer_t remote_gtp_u_peer;
} ogs_pfcp_tlv_user_plane_path_failure_report_t;

typedef struct ogs_pfcp_tlv_create_traffic_endpoint_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_traffic_endpoint_id_t traffic_endpoint_id;
    ogs_pfcp_tlv_f_teid_t local_f_teid;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_redundant_transmission_parameters_t redundant_transmission_detection_parameters;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
    ogs_pfcp_tlv_ethernet_pdu_session_information_t ethernet_pdu_session_information;
    ogs_pfcp_tlv_framed_route_t framed_route;
    ogs_pfcp_tlv_framed_routing_t framed_routing;
    ogs_pfcp_tlv_framed_ipv6_route_t framed_ipv6_route;
    ogs_pfcp_tlv_qfi_t qfi;
    ogs_pfcp_tlv__interface_type_t source_interface_type;
} ogs_pfcp_tlv_create_traffic_endpoint_t;

typedef struct ogs_pfcp_tlv_created_traffic_endpoint_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_traffic_endpoint_id_t traffic_endpoint_id;
    ogs_pfcp_tlv_f_teid_t local_f_teid;
    ogs_pfcp_tlv_f_teid_t local_f_teid_for_redundant_transmission;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
} ogs_pfcp_tlv_created_traffic_endpoint_t;

typedef struct ogs_pfcp_tlv_remove_traffic_endpoint_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_traffic_endpoint_id_t traffic_endpoint_id;
} ogs_pfcp_tlv_remove_traffic_endpoint_t;

typedef struct ogs_pfcp_tlv_create_mar_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mar_id_t mar_id;
    ogs_pfcp_tlv_steering_functionality_t steering_functionality;
    ogs_pfcp_tlv_steering_mode_t steering_mode;
    ogs_pfcp_tlv__access_forwarding_action_information_t _access_forwarding_action_information;
    ogs_pfcp_tlv_non__access_forwarding_action_information_t non__access_forwarding_action_information;
} ogs_pfcp_tlv_create_mar_t;

typedef struct ogs_pfcp_tlv_remove_mar_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mar_id_t mar_id;
} ogs_pfcp_tlv_remove_mar_t;

typedef struct ogs_pfcp_tlv_update_mar_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mar_id_t mar_id;
    ogs_pfcp_tlv_steering_functionality_t steering_functionality;
    ogs_pfcp_tlv_steering_mode_t steering_mode;
    ogs_pfcp_tlv_update__access_forwarding_action_information_t update__access_forwarding_action_information;
    ogs_pfcp_tlv_update_non__access_forwarding_action_information_t update_non__access_forwarding_action_information;
    ogs_pfcp_tlv__access_forwarding_action_information_t _access_forwarding_action_information;
    ogs_pfcp_tlv_non__access_forwarding_action_information_t non__access_forwarding_action_information;
} ogs_pfcp_tlv_update_mar_t;

typedef struct ogs_pfcp_tlv_pfcp_session_retention_information_within_pfcp_association_setup_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_cp_pfcp_entity_ip_address_t cp_pfcp_entity_ip_address;
} ogs_pfcp_tlv_pfcp_session_retention_information_within_pfcp_association_setup_request_t;

typedef struct ogs_pfcp_tlv_user_plane_path_recovery_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_remote_gtp_u_peer_t remote_gtp_u_peer;
} ogs_pfcp_tlv_user_plane_path_recovery_report_t;

typedef struct ogs_pfcp_tlv_created_bridge_info_for_tsc_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ds_tt_port_number_t ds_tt_port_number;
    ogs_pfcp_tlv_tsn_bridge_id_t tsn_bridge_id;
} ogs_pfcp_tlv_created_bridge_info_for_tsc_t;

typedef struct ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_port_management_information_container_t port_management_information_container;
    ogs_pfcp_tlv_bridge_management_information_container_t bridge_management_information_container;
    ogs_pfcp_tlv_nw_tt_port_number_t nw_tt_port_number;
} ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_request_t;

typedef struct ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_response_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_port_management_information_container_t port_management_information_container;
    ogs_pfcp_tlv_bridge_management_information_container_t bridge_management_information_container;
    ogs_pfcp_tlv_nw_tt_port_number_t nw_tt_port_number;
} ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_response_t;

typedef struct ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_report_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_port_management_information_container_t port_management_information_container;
    ogs_pfcp_tlv_bridge_management_information_container_t bridge_management_information_container;
    ogs_pfcp_tlv_nw_tt_port_number_t nw_tt_port_number;
} ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_report_request_t;

typedef struct ogs_pfcp_tlv_clock_drift_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_requested_clock_drift_information_t requested_clock_drift_information;
    ogs_pfcp_tlv_tsn_time_domain_number_t tsn_time_domain_number;
    ogs_pfcp_tlv_time_offset_threshold_t time_offset_threshold;
    ogs_pfcp_tlv_cumulative_rateratio_threshold_t cumulative_rateratio_threshold;
} ogs_pfcp_tlv_clock_drift_control_information_t;

typedef struct ogs_pfcp_tlv_clock_drift_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_tsn_time_domain_number_t tsn_time_domain_number;
    ogs_pfcp_tlv_time_offset_measurement_t time_offset_measurement;
    ogs_pfcp_tlv_cumulative_rateratio_measurement_t cumulative_rateratio_measurement;
    ogs_pfcp_tlv_time_stamp_t time_stamp;
} ogs_pfcp_tlv_clock_drift_report_t;

typedef struct ogs_pfcp_tlv_remove_srr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_srr_id_t srr_id;
} ogs_pfcp_tlv_remove_srr_t;

typedef struct ogs_pfcp_tlv_create_srr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_srr_id_t srr_id;
    ogs_pfcp_tlv_access_availability_control_information_t access_availability_control_information;
    ogs_pfcp_tlv_qos_monitoring_per_qos_flow_control_information_t qos_monitoring_per_qos_flow_control_information;
} ogs_pfcp_tlv_create_srr_t;

typedef struct ogs_pfcp_tlv_update_srr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_srr_id_t srr_id;
    ogs_pfcp_tlv_access_availability_control_information_t access_availability_control_information;
    ogs_pfcp_tlv_qos_monitoring_per_qos_flow_control_information_t qos_monitoring_per_qos_flow_control_information;
} ogs_pfcp_tlv_update_srr_t;

typedef struct ogs_pfcp_tlv_session_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_srr_id_t srr_id;
    ogs_pfcp_tlv_access_availability_report_t access_availability_report;
    ogs_pfcp_tlv_qos_monitoring_report_t qos_monitoring_report;
} ogs_pfcp_tlv_session_report_t;

typedef struct ogs_pfcp_tlv_provide_atsss_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mptcp_control_information_t mptcp_control_information;
    ogs_pfcp_tlv_atsss_ll_control_information_t atsss_ll_control_information;
    ogs_pfcp_tlv_pmf_control_information_t pmf_control_information;
} ogs_pfcp_tlv_provide_atsss_control_information_t;

typedef struct ogs_pfcp_tlv_atsss_control_parameters_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mptcp_parameters_t mptcp_parameters;
    ogs_pfcp_tlv_atsss_ll_parameters_t atsss_ll_parameters;
    ogs_pfcp_tlv_pmf_parameters_t pmf_parameters;
} ogs_pfcp_tlv_atsss_control_parameters_t;

typedef struct ogs_pfcp_tlv_ue_ip_address_pool_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_identity;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_s_nssai_t s_nssai;
    ogs_pfcp_tlv_ip_version_t ip_version;
} ogs_pfcp_tlv_ue_ip_address_pool_information_t;

typedef struct ogs_pfcp_tlv_gtp_u_path_qos_report_pfcp_node_report_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_remote_gtp_u_peer_t remote_gtp_u_peer;
    ogs_pfcp_tlv_gtp_u_path_interface_type_t gtp_u_path_interface_type;
    ogs_pfcp_tlv_qos_report_trigger_t qos_report_trigger;
    ogs_pfcp_tlv_transport_level_marking_t dscp;
    ogs_pfcp_tlv_measurement_period_t measurement_period;
    ogs_pfcp_tlv_average_packet_delay_t average_packet_delay_threshold;
    ogs_pfcp_tlv_minimum_packet_delay_t minimum_packet_delay_threshold;
    ogs_pfcp_tlv_maximum_packet_delay_t maximum_packet_delay_threshold;
    ogs_pfcp_tlv_timer_t minimum_waiting_time;
} ogs_pfcp_tlv_gtp_u_path_qos_report_pfcp_node_report_request_t;

typedef struct ogs_pfcp_tlv_qos_information_in_gtp_u_path_qos_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_average_packet_delay_t average_packet_delay;
    ogs_pfcp_tlv_minimum_packet_delay_t minimum_packet_delay;
    ogs_pfcp_tlv_maximum_packet_delay_t maximum_packet_delay;
    ogs_pfcp_tlv_transport_level_marking_t dscp;
} ogs_pfcp_tlv_qos_information_in_gtp_u_path_qos_report_t;

typedef struct ogs_pfcp_tlv_packet_rate_status_report_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_packet_rate_status_t packet_rate_status;
} ogs_pfcp_tlv_packet_rate_status_report_t;

typedef struct ogs_pfcp_tlv_ethernet_context_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_mac_addresses_detected_t mac_addresses_detected;
} ogs_pfcp_tlv_ethernet_context_information_t;

typedef struct ogs_pfcp_tlv_updated_pdr_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_pdr_id_t pdr_id;
    ogs_pfcp_tlv_f_teid_t local_f_teid_for_redundant_transmission;
    ogs_pfcp_tlv_f_teid_t local_f_teid;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address;
} ogs_pfcp_tlv_updated_pdr_t;

typedef struct ogs_pfcp_tlv_provide_rds_configuration_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_rds_configuration_information_t rds_configuration_information;
} ogs_pfcp_tlv_provide_rds_configuration_information_t;

typedef struct ogs_pfcp_tlv_query_packet_rate_status_ie_within_pfcp_session_modification_request_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
} ogs_pfcp_tlv_query_packet_rate_status_ie_within_pfcp_session_modification_request_t;

typedef struct ogs_pfcp_tlv_packet_rate_status_report_ie_within_pfcp_session_modification_response_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_qer_id_t qer_id;
    ogs_pfcp_tlv_packet_rate_status_t packet_rate_status;
} ogs_pfcp_tlv_packet_rate_status_report_ie_within_pfcp_session_modification_response_t;

typedef struct ogs_pfcp_tlv_ue_ip_address_usage_information_s {
    ogs_tlv_presence_t presence;
    ogs_pfcp_tlv_sequence_number_t ue_ip_address_usage_sequence_number;
    ogs_pfcp_tlv_metric_t ue_ip_address_usage_metric;
    ogs_pfcp_tlv_validity_timer_t validity_timer;
    ogs_pfcp_tlv_number_of_ue_ip_addresses_t number_of_ue_ip_addresses;
    ogs_pfcp_tlv_network_instance_t network_instance;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_id;
} ogs_pfcp_tlv_ue_ip_address_usage_information_t;

/* Structure for Message */
typedef struct ogs_pfcp_heartbeat_request_s {
    ogs_pfcp_tlv_recovery_time_stamp_t recovery_time_stamp;
    ogs_pfcp_tlv_source_ip_address_t source_ip_address;
} ogs_pfcp_heartbeat_request_t;

typedef struct ogs_pfcp_heartbeat_response_s {
    ogs_pfcp_tlv_recovery_time_stamp_t recovery_time_stamp;
} ogs_pfcp_heartbeat_response_t;

typedef struct ogs_pfcp_pfd_management_request_s {
    ogs_pfcp_tlv_application_id_s_pfds_t application_id_s_pfds;
    ogs_pfcp_tlv_node_id_t node_id;
} ogs_pfcp_pfd_management_request_t;

typedef struct ogs_pfcp_pfd_management_response_s {
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
    ogs_pfcp_tlv_node_id_t node_id;
} ogs_pfcp_pfd_management_response_t;

typedef struct ogs_pfcp_association_setup_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_recovery_time_stamp_t recovery_time_stamp;
    ogs_pfcp_tlv_up_function_features_t up_function_features;
    ogs_pfcp_tlv_cp_function_features_t cp_function_features;
    ogs_pfcp_tlv_user_plane_ip_resource_information_t user_plane_ip_resource_information[4];
    ogs_pfcp_tlv_alternative_smf_ip_address_t alternative_smf_ip_address;
    ogs_pfcp_tlv_smf_set_id_t smf_set_id;
    ogs_pfcp_tlv_pfcp_session_retention_information_within_pfcp_association_setup_request_t pfcp_session_retention_information;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_information;
    ogs_pfcp_tlv_gtp_u_path_qos_control_information_t gtp_u_path_qos_control_information;
    ogs_pfcp_tlv_clock_drift_control_information_t clock_drift_control_information;
    ogs_pfcp_tlv_nf_instance_id_t upf_instance_id;
    ogs_pfcp_tlv_pfcpasreq_flags_t pfcpasreq_flags;
} ogs_pfcp_association_setup_request_t;

typedef struct ogs_pfcp_association_setup_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_recovery_time_stamp_t recovery_time_stamp;
    ogs_pfcp_tlv_up_function_features_t up_function_features;
    ogs_pfcp_tlv_cp_function_features_t cp_function_features;
    ogs_pfcp_tlv_user_plane_ip_resource_information_t user_plane_ip_resource_information[4];
    ogs_pfcp_tlv_alternative_smf_ip_address_t alternative_smf_ip_address;
    ogs_pfcp_tlv_smf_set_id_t smf_set_id;
    ogs_pfcp_tlv_pfcpasrsp_flags_t pfcpasrsp_flags;
    ogs_pfcp_tlv_clock_drift_control_information_t clock_drift_control_information;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_information;
    ogs_pfcp_tlv_gtp_u_path_qos_control_information_t gtp_u_path_qos_control_information;
    ogs_pfcp_tlv_nf_instance_id_t upf_instance_id;
} ogs_pfcp_association_setup_response_t;

typedef struct ogs_pfcp_association_update_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_up_function_features_t up_function_features;
    ogs_pfcp_tlv_cp_function_features_t cp_function_features;
    ogs_pfcp_tlv_user_plane_ip_resource_information_t user_plane_ip_resource_information[4];
    ogs_pfcp_tlv_pfcp_association_release_request_t pfcp_association_release_request;
    ogs_pfcp_tlv_graceful_release_period_t graceful_release_period;
    ogs_pfcp_tlv_pfcpaureq_flags_t pfcpaureq_flags;
    ogs_pfcp_tlv_alternative_smf_ip_address_t alternative_smf_ip_address;
    ogs_pfcp_tlv_smf_set_id_t smf_set_id;
    ogs_pfcp_tlv_clock_drift_control_information_t clock_drift_control_information;
    ogs_pfcp_tlv_ue_ip_address_t ue_ip_address_pool_information;
    ogs_pfcp_tlv_gtp_u_path_qos_control_information_t gtp_u_path_qos_control_information;
    ogs_pfcp_tlv_ue_ip_address_usage_information_t ue_ip_address_usage_information;
} ogs_pfcp_association_update_request_t;

typedef struct ogs_pfcp_association_update_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_up_function_features_t up_function_features;
    ogs_pfcp_tlv_cp_function_features_t cp_function_features;
    ogs_pfcp_tlv_ue_ip_address_usage_information_t ue_ip_address_usage_information;
} ogs_pfcp_association_update_response_t;

typedef struct ogs_pfcp_association_release_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
} ogs_pfcp_association_release_request_t;

typedef struct ogs_pfcp_association_release_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
} ogs_pfcp_association_release_response_t;

typedef struct ogs_pfcp_version_not_supported_response_s {
} ogs_pfcp_version_not_supported_response_t;

typedef struct ogs_pfcp_node_report_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_node_report_type_t node_report_type;
    ogs_pfcp_tlv_user_plane_path_failure_report_t user_plane_path_failure_report;
    ogs_pfcp_tlv_user_plane_path_recovery_report_t user_plane_path_recovery_report;
    ogs_pfcp_tlv_clock_drift_report_t clock_drift_report;
    ogs_pfcp_tlv_gtp_u_path_qos_report_pfcp_node_report_request_t gtp_u_path_qos_report;
} ogs_pfcp_node_report_request_t;

typedef struct ogs_pfcp_node_report_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
} ogs_pfcp_node_report_response_t;

typedef struct ogs_pfcp_session_set_deletion_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_fq_csid_t sgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t pgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t pgw_u_sgw_u_fq_csid;
    ogs_pfcp_tlv_fq_csid_t twan_fq_csid;
    ogs_pfcp_tlv_fq_csid_t epdg_fq_csid;
    ogs_pfcp_tlv_fq_csid_t mme_fq_csid;
} ogs_pfcp_session_set_deletion_request_t;

typedef struct ogs_pfcp_session_set_deletion_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
} ogs_pfcp_session_set_deletion_response_t;

typedef struct ogs_pfcp_session_establishment_request_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_f_seid_t cp_f_seid;
    ogs_pfcp_tlv_create_pdr_t create_pdr[16];
    ogs_pfcp_tlv_create_far_t create_far[16];
    ogs_pfcp_tlv_create_urr_t create_urr[16];
    ogs_pfcp_tlv_create_qer_t create_qer[4];
    ogs_pfcp_tlv_create_bar_t create_bar;
    ogs_pfcp_tlv_create_traffic_endpoint_t create_traffic_endpoint;
    ogs_pfcp_tlv_pdn_type_t pdn_type;
    ogs_pfcp_tlv_fq_csid_t sgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t mme_fq_csid;
    ogs_pfcp_tlv_fq_csid_t pgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t epdg_fq_csid;
    ogs_pfcp_tlv_fq_csid_t twan_fq_csid;
    ogs_pfcp_tlv_user_plane_inactivity_timer_t user_plane_inactivity_timer;
    ogs_pfcp_tlv_user_id_t user_id;
    ogs_pfcp_tlv_trace_information_t trace_information;
    ogs_pfcp_tlv_apn_dnn_t apn_dnn;
    ogs_pfcp_tlv_create_mar_t create_mar;
    ogs_pfcp_tlv_pfcpsereq_flags_t pfcpsereq_flags;
    ogs_pfcp_tlv_create_bridge_info_for_tsc_t create_bridge_info_for_tsc;
    ogs_pfcp_tlv_create_srr_t create_srr;
    ogs_pfcp_tlv_provide_atsss_control_information_t provide_atsss_control_information;
    ogs_pfcp_tlv_recovery_time_stamp_t recovery_time_stamp;
    ogs_pfcp_tlv_s_nssai_t s_nssai;
    ogs_pfcp_tlv_provide_rds_configuration_information_t provide_rds_configuration_information;
} ogs_pfcp_session_establishment_request_t;

typedef struct ogs_pfcp_session_establishment_response_s {
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
    ogs_pfcp_tlv_f_seid_t up_f_seid;
    ogs_pfcp_tlv_created_pdr_t created_pdr[16];
    ogs_pfcp_tlv_load_control_information_t load_control_information;
    ogs_pfcp_tlv_overload_control_information_t overload_control_information;
    ogs_pfcp_tlv_fq_csid_t pgw_u_sgw_u_fq_csid;
    ogs_pfcp_tlv_failed_rule_id_t failed_rule_id;
    ogs_pfcp_tlv_created_traffic_endpoint_t created_traffic_endpoint;
    ogs_pfcp_tlv_created_bridge_info_for_tsc_t created_bridge_info_for_tsc;
    ogs_pfcp_tlv_atsss_control_parameters_t atsss_control_parameters;
    ogs_pfcp_tlv_rds_configuration_information_t rds_configuration_information;
} ogs_pfcp_session_establishment_response_t;

typedef struct ogs_pfcp_session_modification_request_s {
    ogs_pfcp_tlv_f_seid_t cp_f_seid;
    ogs_pfcp_tlv_remove_pdr_t remove_pdr[16];
    ogs_pfcp_tlv_remove_far_t remove_far[16];
    ogs_pfcp_tlv_remove_urr_t remove_urr[16];
    ogs_pfcp_tlv_remove_qer_t remove_qer[4];
    ogs_pfcp_tlv_remove_bar_t remove_bar;
    ogs_pfcp_tlv_remove_traffic_endpoint_t remove_traffic_endpoint;
    ogs_pfcp_tlv_create_pdr_t create_pdr[16];
    ogs_pfcp_tlv_create_far_t create_far[16];
    ogs_pfcp_tlv_create_urr_t create_urr[16];
    ogs_pfcp_tlv_create_qer_t create_qer[4];
    ogs_pfcp_tlv_create_bar_t create_bar;
    ogs_pfcp_tlv_create_traffic_endpoint_t create_traffic_endpoint;
    ogs_pfcp_tlv_update_pdr_t update_pdr[16];
    ogs_pfcp_tlv_update_far_t update_far[16];
    ogs_pfcp_tlv_update_urr_t update_urr[16];
    ogs_pfcp_tlv_update_qer_t update_qer[4];
    ogs_pfcp_tlv_update_bar_session_modification_request_t update_bar;
    ogs_pfcp_tlv_update_traffic_endpoint_t update_traffic_endpoint;
    ogs_pfcp_tlv_pfcpsmreq_flags_t pfcpsmreq_flags;
    ogs_pfcp_tlv_query_urr_t query_urr;
    ogs_pfcp_tlv_fq_csid_t pgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t sgw_c_fq_csid;
    ogs_pfcp_tlv_fq_csid_t mme_fq_csid;
    ogs_pfcp_tlv_fq_csid_t epdg_fq_csid;
    ogs_pfcp_tlv_fq_csid_t twan_fq_csid;
    ogs_pfcp_tlv_user_plane_inactivity_timer_t user_plane_inactivity_timer;
    ogs_pfcp_tlv_query_urr_reference_t query_urr_reference;
    ogs_pfcp_tlv_trace_information_t trace_information;
    ogs_pfcp_tlv_remove_mar_t remove_mar;
    ogs_pfcp_tlv_update_mar_t update_mar;
    ogs_pfcp_tlv_create_mar_t create_mar;
    ogs_pfcp_tlv_node_id_t node_id;
    ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_request_t tsc_management_information;
    ogs_pfcp_tlv_remove_srr_t remove_srr;
    ogs_pfcp_tlv_create_srr_t create_srr;
    ogs_pfcp_tlv_update_srr_t update_srr;
    ogs_pfcp_tlv_provide_atsss_control_information_t provide_atsss_control_information;
    ogs_pfcp_tlv_ethernet_context_information_t ethernet_context_information;
    ogs_pfcp_tlv_access_availability_information_t access_availability_information;
    ogs_pfcp_tlv_query_packet_rate_status_ie_within_pfcp_session_modification_request_t query_packet_rate_status;
    ogs_pfcp_tlv_s_nssai_t s_nssai;
} ogs_pfcp_session_modification_request_t;

typedef struct ogs_pfcp_session_modification_response_s {
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
    ogs_pfcp_tlv_created_pdr_t created_pdr[16];
    ogs_pfcp_tlv_load_control_information_t load_control_information;
    ogs_pfcp_tlv_overload_control_information_t overload_control_information;
    ogs_pfcp_tlv_usage_report_session_modification_response_t usage_report[8];
    ogs_pfcp_tlv_failed_rule_id_t failed_rule_id;
    ogs_pfcp_tlv_additional_usage_reports_information_t additional_usage_reports_information;
    ogs_pfcp_tlv_created_traffic_endpoint_t created_updated_traffic_endpoint;
    ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_modification_response_t tsc_management_information;
    ogs_pfcp_tlv_atsss_control_parameters_t atsss_control_parameters;
    ogs_pfcp_tlv_updated_pdr_t updated_pdr;
    ogs_pfcp_tlv_packet_rate_status_report_ie_within_pfcp_session_modification_response_t packet_rate_status_report;
} ogs_pfcp_session_modification_response_t;

typedef struct ogs_pfcp_session_deletion_request_s {
} ogs_pfcp_session_deletion_request_t;

typedef struct ogs_pfcp_session_deletion_response_s {
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
    ogs_pfcp_tlv_load_control_information_t load_control_information;
    ogs_pfcp_tlv_overload_control_information_t overload_control_information;
    ogs_pfcp_tlv_usage_report_session_deletion_response_t usage_report[8];
    ogs_pfcp_tlv_additional_usage_reports_information_t additional_usage_reports_information;
    ogs_pfcp_tlv_packet_rate_status_report_t packet_rate_status_report;
    ogs_pfcp_tlv_session_report_t session_report;
} ogs_pfcp_session_deletion_response_t;

typedef struct ogs_pfcp_session_report_request_s {
    ogs_pfcp_tlv_report_type_t report_type;
    ogs_pfcp_tlv_downlink_data_report_t downlink_data_report;
    ogs_pfcp_tlv_usage_report_session_report_request_t usage_report[8];
    ogs_pfcp_tlv_error_indication_report_t error_indication_report;
    ogs_pfcp_tlv_load_control_information_t load_control_information;
    ogs_pfcp_tlv_overload_control_information_t overload_control_information;
    ogs_pfcp_tlv_additional_usage_reports_information_t additional_usage_reports_information;
    ogs_pfcp_tlv_pfcpsrreq_flags_t pfcpsrreq_flags;
    ogs_pfcp_tlv_f_seid_t old_cp_f_seid;
    ogs_pfcp_tlv_packet_rate_status_report_t packet_rate_status_report;
    ogs_pfcp_tlv_tsc_management_information_ie_within_pfcp_session_report_request_t tsc_management_information;
    ogs_pfcp_tlv_session_report_t session_report;
} ogs_pfcp_session_report_request_t;

typedef struct ogs_pfcp_session_report_response_s {
    ogs_pfcp_tlv_cause_t cause;
    ogs_pfcp_tlv_offending_ie_t offending_ie;
    ogs_pfcp_tlv_update_bar_pfcp_session_report_response_t update_bar;
    ogs_pfcp_tlv_pfcpsrrsp_flags_t pfcpsrrsp_flags;
    ogs_pfcp_tlv_f_seid_t cp_f_seid;
    ogs_pfcp_tlv_f_teid_t n4_u_f_teid;
    ogs_pfcp_tlv_alternative_smf_ip_address_t alternative_smf_ip_address;
} ogs_pfcp_session_report_response_t;

typedef struct ogs_pfcp_message_s {
   ogs_pfcp_header_t h;
   union {
        ogs_pfcp_heartbeat_request_t pfcp_heartbeat_request;
        ogs_pfcp_heartbeat_response_t pfcp_heartbeat_response;
        ogs_pfcp_pfd_management_request_t pfcp_pfd_management_request;
        ogs_pfcp_pfd_management_response_t pfcp_pfd_management_response;
        ogs_pfcp_association_setup_request_t pfcp_association_setup_request;
        ogs_pfcp_association_setup_response_t pfcp_association_setup_response;
        ogs_pfcp_association_update_request_t pfcp_association_update_request;
        ogs_pfcp_association_update_response_t pfcp_association_update_response;
        ogs_pfcp_association_release_request_t pfcp_association_release_request;
        ogs_pfcp_association_release_response_t pfcp_association_release_response;
        ogs_pfcp_version_not_supported_response_t pfcp_version_not_supported_response;
        ogs_pfcp_node_report_request_t pfcp_node_report_request;
        ogs_pfcp_node_report_response_t pfcp_node_report_response;
        ogs_pfcp_session_set_deletion_request_t pfcp_session_set_deletion_request;
        ogs_pfcp_session_set_deletion_response_t pfcp_session_set_deletion_response;
        ogs_pfcp_session_establishment_request_t pfcp_session_establishment_request;
        ogs_pfcp_session_establishment_response_t pfcp_session_establishment_response;
        ogs_pfcp_session_modification_request_t pfcp_session_modification_request;
        ogs_pfcp_session_modification_response_t pfcp_session_modification_response;
        ogs_pfcp_session_deletion_request_t pfcp_session_deletion_request;
        ogs_pfcp_session_deletion_response_t pfcp_session_deletion_response;
        ogs_pfcp_session_report_request_t pfcp_session_report_request;
        ogs_pfcp_session_report_response_t pfcp_session_report_response;
   };
} ogs_pfcp_message_t;

ogs_pfcp_message_t *ogs_pfcp_parse_msg(ogs_pkbuf_t *pkbuf);
void ogs_pfcp_message_free(ogs_pfcp_message_t *pfcp_message);
ogs_pkbuf_t *ogs_pfcp_build_msg(ogs_pfcp_message_t *pfcp_message);

#ifdef __cplusplus
}
#endif

#endif /* OGS_PFCP_MESSAGE_H */
