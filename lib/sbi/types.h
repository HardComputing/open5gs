/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
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

#if !defined(OGS_SBI_INSIDE) && !defined(OGS_SBI_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_SBI_TYPES_H
#define OGS_SBI_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OGS_SBI_SERVICE_TYPE_NULL = 0,

    OGS_SBI_SERVICE_TYPE_NNRF_NFM,
    OGS_SBI_SERVICE_TYPE_NNRF_DISC,
    OGS_SBI_SERVICE_TYPE_NNRF_OAUTH2,
    OGS_SBI_SERVICE_TYPE_NUDM_SDM,
    OGS_SBI_SERVICE_TYPE_NUDM_UECM,
    OGS_SBI_SERVICE_TYPE_NUDM_UEAU,
    OGS_SBI_SERVICE_TYPE_NUDM_EE,
    OGS_SBI_SERVICE_TYPE_NUDM_PP,
    OGS_SBI_SERVICE_TYPE_NUDM_NIDDAU,
    OGS_SBI_SERVICE_TYPE_NUDM_MT,
    OGS_SBI_SERVICE_TYPE_NAMF_COMM,
    OGS_SBI_SERVICE_TYPE_NAMF_EVTS,
    OGS_SBI_SERVICE_TYPE_NAMF_MT,
    OGS_SBI_SERVICE_TYPE_NAMF_LOC,
    OGS_SBI_SERVICE_TYPE_NSMF_PDUSESSION,
    OGS_SBI_SERVICE_TYPE_NSMF_EVENT_EXPOSURE,
    OGS_SBI_SERVICE_TYPE_NSMF_NIDD,
    OGS_SBI_SERVICE_TYPE_NAUSF_AUTH,
    OGS_SBI_SERVICE_TYPE_NAUSF_SORPROTECTION,
    OGS_SBI_SERVICE_TYPE_NAUSF_UPUPROTECTION,
    OGS_SBI_SERVICE_TYPE_NNEF_PFDMANAGEMENT,
    OGS_SBI_SERVICE_TYPE_NNEF_SMCONTEXT,
    OGS_SBI_SERVICE_TYPE_NNEF_EVENTEXPOSURE,
    OGS_SBI_SERVICE_TYPE_NPCF_AM_POLICY_CONTROL,
    OGS_SBI_SERVICE_TYPE_NPCF_SMPOLICYCONTROL,
    OGS_SBI_SERVICE_TYPE_NPCF_POLICYAUTHORIZATION,
    OGS_SBI_SERVICE_TYPE_NPCF_BDTPOLICYCONTROL,
    OGS_SBI_SERVICE_TYPE_NPCF_EVENTEXPOSURE,
    OGS_SBI_SERVICE_TYPE_NPCF_UE_POLICY_CONTROL,
    OGS_SBI_SERVICE_TYPE_NSMSF_SMS,
    OGS_SBI_SERVICE_TYPE_NNSSF_NSSELECTION,
    OGS_SBI_SERVICE_TYPE_NNSSF_NSSAIAVAILABILITY,
    OGS_SBI_SERVICE_TYPE_NUDR_DR,
    OGS_SBI_SERVICE_TYPE_NUDR_GROUP_ID_MAP,
    OGS_SBI_SERVICE_TYPE_NLMF_LOC,
    OGS_SBI_SERVICE_TYPE_N5G_EIR_EIC,
    OGS_SBI_SERVICE_TYPE_NBSF_MANAGEMENT,
    OGS_SBI_SERVICE_TYPE_NCHF_SPENDINGLIMITCONTROL,
    OGS_SBI_SERVICE_TYPE_NCHF_CONVERGEDCHARGING,
    OGS_SBI_SERVICE_TYPE_NCHF_OFFLINEONLYCHARGING,
    OGS_SBI_SERVICE_TYPE_NNWDAF_EVENTSSUBSCRIPTION,
    OGS_SBI_SERVICE_TYPE_NNWDAF_ANALYTICSINFO,
    OGS_SBI_SERVICE_TYPE_NGMLC_LOC,
    OGS_SBI_SERVICE_TYPE_NUCMF_PROVISIONING,
    OGS_SBI_SERVICE_TYPE_NUCMF_UECAPABILITYMANAGEMENT,
    OGS_SBI_SERVICE_TYPE_NHSS_SDM,
    OGS_SBI_SERVICE_TYPE_NHSS_UECM,
    OGS_SBI_SERVICE_TYPE_NHSS_UEAU,
    OGS_SBI_SERVICE_TYPE_NHSS_EE,
    OGS_SBI_SERVICE_TYPE_NHSS_IMS_SDM,
    OGS_SBI_SERVICE_TYPE_NHSS_IMS_UECM,
    OGS_SBI_SERVICE_TYPE_NHSS_IMS_UEAU,
    OGS_SBI_SERVICE_TYPE_NSEPP_TELESCOPIC,
    OGS_SBI_SERVICE_TYPE_NSORAF_SOR,
    OGS_SBI_SERVICE_TYPE_NSPAF_SECURED_PACKET,
    OGS_SBI_SERVICE_TYPE_NUDSF_DR,
    OGS_SBI_SERVICE_TYPE_NNSSAAF_NSSAA,

    OGS_SBI_MAX_NUM_OF_SERVICE_TYPE,
} ogs_sbi_service_type_e;

#define OGS_SBI_SERVICE_NAME_NNRF_NFM "nnrf-nfm"
#define OGS_SBI_SERVICE_NAME_NNRF_DISC "nnrf-disc"
#define OGS_SBI_SERVICE_NAME_NNRF_OAUTH2 "nnrf-oauth2"
#define OGS_SBI_SERVICE_NAME_NUDM_SDM "nudm-sdm"
#define OGS_SBI_SERVICE_NAME_NUDM_UECM "nudm-uecm"
#define OGS_SBI_SERVICE_NAME_NUDM_UEAU "nudm-ueau"
#define OGS_SBI_SERVICE_NAME_NUDM_EE "nudm-ee"
#define OGS_SBI_SERVICE_NAME_NUDM_PP "nudm-pp"
#define OGS_SBI_SERVICE_NAME_NUDM_NIDDAU "nudm-niddau"
#define OGS_SBI_SERVICE_NAME_NUDM_MT "nudm-mt"
#define OGS_SBI_SERVICE_NAME_NAMF_COMM "namf-comm"
#define OGS_SBI_SERVICE_NAME_NAMF_EVTS "namf-evts"
#define OGS_SBI_SERVICE_NAME_NAMF_MT "namf-mt"
#define OGS_SBI_SERVICE_NAME_NAMF_LOC "namf-loc"
#define OGS_SBI_SERVICE_NAME_NSMF_PDUSESSION "nsmf-pdusession"
#define OGS_SBI_SERVICE_NAME_NSMF_EVENT_EXPOSURE "nsmf-event-exposure"
#define OGS_SBI_SERVICE_NAME_NSMF_NIDD "nsmf-nidd"
#define OGS_SBI_SERVICE_NAME_NAUSF_AUTH "nausf-auth"
#define OGS_SBI_SERVICE_NAME_NAUSF_SORPROTECTION "nausf-sorprotection"
#define OGS_SBI_SERVICE_NAME_NAUSF_UPUPROTECTION "nausf-upuprotection"
#define OGS_SBI_SERVICE_NAME_NNEF_PFDMANAGEMENT "nnef-pfdmanagement"
#define OGS_SBI_SERVICE_NAME_NNEF_SMCONTEXT "nnef-smcontext"
#define OGS_SBI_SERVICE_NAME_NNEF_EVENTEXPOSURE "nnef-eventexposure"
#define OGS_SBI_SERVICE_NAME_NPCF_AM_POLICY_CONTROL "npcf-am-policy-control"
#define OGS_SBI_SERVICE_NAME_NPCF_SMPOLICYCONTROL "npcf-smpolicycontrol"
#define OGS_SBI_SERVICE_NAME_NPCF_POLICYAUTHORIZATION "npcf-policyauthorization"
#define OGS_SBI_SERVICE_NAME_NPCF_BDTPOLICYCONTROL "npcf-bdtpolicycontrol"
#define OGS_SBI_SERVICE_NAME_NPCF_EVENTEXPOSURE "npcf-eventexposure"
#define OGS_SBI_SERVICE_NAME_NPCF_UE_POLICY_CONTROL "npcf-ue-policy-control"
#define OGS_SBI_SERVICE_NAME_NSMSF_SMS "nsmsf-sms"
#define OGS_SBI_SERVICE_NAME_NNSSF_NSSELECTION "nnssf-nsselection"
#define OGS_SBI_SERVICE_NAME_NNSSF_NSSAIAVAILABILITY "nnssf-nssaiavailability"
#define OGS_SBI_SERVICE_NAME_NUDR_DR "nudr-dr"
#define OGS_SBI_SERVICE_NAME_NUDR_GROUP_ID_MAP "nudr-group-id-map"
#define OGS_SBI_SERVICE_NAME_NTDF_FIRST "ntdf-first"
#define OGS_SBI_SERVICE_NAME_NTDF_SECOND "ntdf-second"
#define OGS_SBI_SERVICE_NAME_NLMF_LOC "nlmf-loc"
#define OGS_SBI_SERVICE_NAME_N5G_EIR_EIC "n5g-eir-eic"
#define OGS_SBI_SERVICE_NAME_NBSF_MANAGEMENT "nbsf-management"
#define OGS_SBI_SERVICE_NAME_NCHF_SPENDINGLIMITCONTROL \
    "nchf-spendinglimitcontrol"
#define OGS_SBI_SERVICE_NAME_NCHF_CONVERGEDCHARGING "nchf-convergedcharging"
#define OGS_SBI_SERVICE_NAME_NCHF_OFFLINEONLYCHARGING "nchf-offlineonlycharging"
#define OGS_SBI_SERVICE_NAME_NNWDAF_EVENTSSUBSCRIPTION \
    "nnwdaf-eventssubscription"
#define OGS_SBI_SERVICE_NAME_NNWDAF_ANALYTICSINFO "nnwdaf-analyticsinfo"
#define OGS_SBI_SERVICE_NAME_NGMLC_LOC "ngmlc-loc"
#define OGS_SBI_SERVICE_NAME_NUCMF_PROVISIONING "nucmf-provisioning"
#define OGS_SBI_SERVICE_NAME_NUCMF_UECAPABILITYMANAGEMENT \
    "nucmf-uecapabilitymanagement"
#define OGS_SBI_SERVICE_NAME_NHSS_SDM "nhss-sdm"
#define OGS_SBI_SERVICE_NAME_NHSS_UECM "nhss-uecm"
#define OGS_SBI_SERVICE_NAME_NHSS_UEAU "nhss-ueau"
#define OGS_SBI_SERVICE_NAME_NHSS_EE "nhss-ee"
#define OGS_SBI_SERVICE_NAME_NHSS_IMS_SDM "nhss-ims-sdm"
#define OGS_SBI_SERVICE_NAME_NHSS_IMS_UECM "nhss-ims-uecm"
#define OGS_SBI_SERVICE_NAME_NHSS_IMS_UEAU "nhss-ims-ueau"
#define OGS_SBI_SERVICE_NAME_NSEPP_TELESCOPIC "nsepp-telescopic"
#define OGS_SBI_SERVICE_NAME_NSORAF_SOR "nsoraf-sor"
#define OGS_SBI_SERVICE_NAME_NSPAF_SECURED_PACKET "nspaf-secured-packet"
#define OGS_SBI_SERVICE_NAME_NUDSF_DR "nudsf-dr"
#define OGS_SBI_SERVICE_NAME_NNSSAAF_NSSAA "nnssaaf-nssaa"

#define OGS_SBI_SERVICE_NAME_NAMF_CALLBACK "namf-callback"
#define OGS_SBI_SERVICE_NAME_NSMF_CALLBACK "nsmf-callback"

#define OGS_SBI_SERVICE_NAME_ANONYMOUS "ngeneral"

OpenAPI_nf_type_e ogs_sbi_service_type_to_nf_type(
        ogs_sbi_service_type_e service_type);
const char *ogs_sbi_service_type_to_name(ogs_sbi_service_type_e service_type);
ogs_sbi_service_type_e ogs_sbi_service_type_from_name(const char *service_name);


#ifdef __cplusplus
}
#endif

#endif /* OGS_SBI_TYPES_H */
