/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_GNSS_RTK_FKP_Gradients_r15_H_
#define	_GNSS_RTK_FKP_Gradients_r15_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GNSS-ReferenceStationID-r15.h"
#include "GNSS-SystemTime.h"
#include "FKP-Gradients-List-r15.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct GNSS_FrequencyID_r15;

/* GNSS-RTK-FKP-Gradients-r15 */
typedef struct GNSS_RTK_FKP_Gradients_r15 {
	GNSS_ReferenceStationID_r15_t	 referenceStationID_r15;
	GNSS_SystemTime_t	 epochTime_r15;
	struct GNSS_FrequencyID_r15	*l1_r15	/* OPTIONAL */;
	struct GNSS_FrequencyID_r15	*l2_r15	/* OPTIONAL */;
	FKP_Gradients_List_r15_t	 fkp_gradients_list_r15;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GNSS_RTK_FKP_Gradients_r15_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNSS_RTK_FKP_Gradients_r15;
extern asn_SEQUENCE_specifics_t asn_SPC_GNSS_RTK_FKP_Gradients_r15_specs_1;
extern asn_TYPE_member_t asn_MBR_GNSS_RTK_FKP_Gradients_r15_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "GNSS-FrequencyID-r15.h"

#endif	/* _GNSS_RTK_FKP_Gradients_r15_H_ */
#include <asn_internal.h>
