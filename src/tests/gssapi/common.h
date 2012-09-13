/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* tests/gssapi/common.h - Declarations for GSSAPI test utility functions */
/*
 * Copyright (C) 2012 by the Massachusetts Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef COMMON_H
#define COMMON_H

#include <gssapi/gssapi_krb5.h>

gss_OID_desc mech_krb5;
gss_OID_desc mech_spnego;
gss_OID_desc mech_iakerb;
gss_OID_set_desc mechset_krb5;
gss_OID_set_desc mechset_spnego;
gss_OID_set_desc mechset_iakerb;

/* Display an error message (containing msg) and exit if major is an error. */
void check_gsserr(const char *msg, OM_uint32 major, OM_uint32 minor);

/* Display an error message (containing msg) and exit if code is an error. */
void check_k5err(krb5_context context, const char *msg, krb5_error_code code);

/* Display an error message containing msg and exit. */
void errout(const char *msg);

/* Import a GSSAPI name based on a string of the form 'u:username',
 * 'p:principalname', or 'h:host@service' (or just 'h:service'). */
gss_name_t import_name(const char *str);

/* Display name as canonicalized to mech, preceded by tag. */
void display_canon_name(const char *tag, gss_name_t name, gss_OID mech);

/* Display oid in printable form, preceded by tag. */
void display_oid(const char *tag, gss_OID oid);

/* Display attributes of name, including hex value if noisy is true. */
void enumerate_attributes(gss_name_t name, int noisy);

/* Display the contents of buf to fp in hex, followed by a newline. */
void print_hex(FILE *fp, gss_buffer_t buf);

#endif /* COMMON_H */