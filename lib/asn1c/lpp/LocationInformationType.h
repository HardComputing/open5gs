/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_LocationInformationType_H_
#define	_LocationInformationType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LocationInformationType {
	LocationInformationType_locationEstimateRequired	= 0,
	LocationInformationType_locationMeasurementsRequired	= 1,
	LocationInformationType_locationEstimatePreferred	= 2,
	LocationInformationType_locationMeasurementsPreferred	= 3
	/*
	 * Enumeration is extensible
	 */
} e_LocationInformationType;

/* LocationInformationType */
typedef long	 LocationInformationType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LocationInformationType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LocationInformationType;
extern const asn_INTEGER_specifics_t asn_SPC_LocationInformationType_specs_1;
asn_struct_free_f LocationInformationType_free;
asn_struct_print_f LocationInformationType_print;
asn_constr_check_f LocationInformationType_constraint;
ber_type_decoder_f LocationInformationType_decode_ber;
der_type_encoder_f LocationInformationType_encode_der;
xer_type_decoder_f LocationInformationType_decode_xer;
xer_type_encoder_f LocationInformationType_encode_xer;
per_type_decoder_f LocationInformationType_decode_uper;
per_type_encoder_f LocationInformationType_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LocationInformationType_H_ */
#include <asn_internal.h>
