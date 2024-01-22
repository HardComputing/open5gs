/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_BT_MeasurementElement_r13_H_
#define	_BT_MeasurementElement_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BT-MeasurementElement-r13 */
typedef struct BT_MeasurementElement_r13 {
	BIT_STRING_t	 btAddr_r13;
	long	*rssi_r13	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BT_MeasurementElement_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BT_MeasurementElement_r13;
extern asn_SEQUENCE_specifics_t asn_SPC_BT_MeasurementElement_r13_specs_1;
extern asn_TYPE_member_t asn_MBR_BT_MeasurementElement_r13_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _BT_MeasurementElement_r13_H_ */
#include <asn_internal.h>
