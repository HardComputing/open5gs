/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_UTC_ModelSet3_H_
#define	_UTC_ModelSet3_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UTC-ModelSet3 */
typedef struct UTC_ModelSet3 {
	long	 nA;
	long	 tauC;
	long	*b1	/* OPTIONAL */;
	long	*b2	/* OPTIONAL */;
	BIT_STRING_t	*kp	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UTC_ModelSet3_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UTC_ModelSet3;
extern asn_SEQUENCE_specifics_t asn_SPC_UTC_ModelSet3_specs_1;
extern asn_TYPE_member_t asn_MBR_UTC_ModelSet3_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _UTC_ModelSet3_H_ */
#include <asn_internal.h>
