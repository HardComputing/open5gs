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

#ifndef MAF_CONTEXT_H
#define MAF_CONTEXT_H

#include "ogs-app.h"
#include "ogs-dbi.h"
#include "ogs-sbi.h"

#include "maf-sm.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int __maf_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __maf_log_domain

typedef struct maf_context_s {
} maf_context_t;

void maf_context_init(void);
void maf_context_final(void);
maf_context_t *maf_self(void);

int maf_context_parse_config(void);

#ifdef __cplusplus
}
#endif

#endif /* MAF_CONTEXT_H */
