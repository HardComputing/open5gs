/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "GNSS-ClockModel.h"

asn_per_constraints_t asn_PER_type_GNSS_ClockModel_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  4 }	/* (0..4,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_GNSS_ClockModel_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.standardClockModelList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_StandardClockModelList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"standardClockModelList"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.nav_ClockModel),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NAV_ClockModel,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nav-ClockModel"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.cnav_ClockModel),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CNAV_ClockModel,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cnav-ClockModel"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.glonass_ClockModel),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GLONASS_ClockModel,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"glonass-ClockModel"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.sbas_ClockModel),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SBAS_ClockModel,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sbas-ClockModel"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.bds_ClockModel_r12),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BDS_ClockModel_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"bds-ClockModel-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.bds_ClockModel2_r16),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BDS_ClockModel2_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"bds-ClockModel2-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GNSS_ClockModel, choice.navic_ClockModel_r16),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NavIC_ClockModel_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"navic-ClockModel-r16"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_GNSS_ClockModel_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* standardClockModelList */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* nav-ClockModel */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* cnav-ClockModel */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* glonass-ClockModel */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* sbas-ClockModel */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* bds-ClockModel-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* bds-ClockModel2-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* navic-ClockModel-r16 */
};
asn_CHOICE_specifics_t asn_SPC_GNSS_ClockModel_specs_1 = {
	sizeof(struct GNSS_ClockModel),
	offsetof(struct GNSS_ClockModel, _asn_ctx),
	offsetof(struct GNSS_ClockModel, present),
	sizeof(((struct GNSS_ClockModel *)0)->present),
	asn_MAP_GNSS_ClockModel_tag2el_1,
	8,	/* Count of tags in the map */
	0, 0,
	5	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_GNSS_ClockModel = {
	"GNSS-ClockModel",
	"GNSS-ClockModel",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_GNSS_ClockModel_constr_1, CHOICE_constraint },
	asn_MBR_GNSS_ClockModel_1,
	8,	/* Elements count */
	&asn_SPC_GNSS_ClockModel_specs_1	/* Additional specs */
};

