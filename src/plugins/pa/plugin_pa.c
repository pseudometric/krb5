/*
 * plugin_pa.c
 *
 */
#include <plugin_manager.h>
#include "plugin_pa.h"

int
plugin_preauth_flags(plhandle handle, krb5_context context, krb5_preauthtype pa_type)
{
    int flags = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    flags = api->preauth_flags(context, pa_type);
    return flags;

}
krb5_error_code
plugin_process_preauth(plhandle handle, krb5_context context, void *plugin_context,
                                       void *request_context, krb5_get_init_creds_opt *opt,
                                       preauth_get_client_data_proc get_data_proc,
                                       struct _krb5_preauth_client_rock *rock, krb5_kdc_req *request,
                                       krb5_data *encoded_request_body,
                                       krb5_data *encoded_previous_request, krb5_pa_data *padata,
                                       krb5_prompter_fct prompter, void *prompter_data,
                                       preauth_get_as_key_proc gak_fct, void *gak_data,
                                       krb5_data *salt, krb5_data *s2kparams, krb5_keyblock *as_key,
                                       krb5_pa_data ***out_padata)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->process_preauth(context, plugin_context,
                                       request_context, opt,
                                       get_data_proc,
                                       rock, request,
                                       encoded_request_body,
                                       encoded_previous_request, padata,
                                       prompter, prompter_data,
                                       gak_fct, gak_data,
                                       salt, s2kparams, as_key,
                                       out_padata);
    return retval;

}

krb5_error_code
plugin_kdc_include_padata(plhandle handle, krb5_context context, krb5_kdc_req *request,
                                          struct _krb5_db_entry_new *client,
                                          struct _krb5_db_entry_new *server,
                                          preauth_get_entry_data_proc get_entry_proc,
                                          void *pa_module_context, krb5_pa_data *data)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->kdc_include_padata(context, request,
                                         client,
                                         server,
                                         get_entry_proc,
                                         pa_module_context, data);
    return retval;
}
krb5_error_code
plugin_kdc_verify_preauth(plhandle handle, krb5_context context, struct _krb5_db_entry_new *client,
                                          krb5_data *req_pkt, krb5_kdc_req *request,
                                          krb5_enc_tkt_part *enc_tkt_reply, krb5_pa_data *data,
                                          preauth_get_entry_data_proc get_entry_proc,
                                          void *pa_module_context, void **pa_request_context,
                                          krb5_data **e_data, krb5_authdata ***authz_data)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->kdc_verify_preauth(context, client,
                                          req_pkt, request,
                                          enc_tkt_reply, data,
                                          get_entry_proc,
                                          pa_module_context, pa_request_context,
                                          e_data, authz_data);
    return retval;
}

krb5_error_code
plugin_kdc_return_preauth(plhandle handle, krb5_context context, krb5_pa_data *padata,
                                          struct _krb5_db_entry_new *client, krb5_data *req_pkt,
                                          krb5_kdc_req *request, krb5_kdc_rep *reply,
                                          struct _krb5_key_data *client_keys,
                                          krb5_keyblock *encrypting_key, krb5_pa_data **send_pa,
                                          preauth_get_entry_data_proc get_entry_proc,
                                          void *pa_module_context, void **pa_request_context)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->kdc_return_preauth(context, padata,
                                          client, req_pkt,
                                          request, reply,
                                          client_keys,
                                          encrypting_key, send_pa,
                                          get_entry_proc,
                                          pa_module_context, pa_request_context);
    return retval;

}
krb5_error_code
plugin_server_free_reqctx(plhandle handle, krb5_context kcontext,
                                          void *pa_module_context,
                                          void **pa_request_context)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->server_free_reqctx(kcontext,
                                          pa_module_context,
                                          pa_request_context);
    return retval;
}
krb5_error_code
plugin_server_init(plhandle handle, krb5_context kcontext, void **module_context, const char **realmnames)
{
    krb5_error_code retval = 0;
    plugin_pa* api = (plugin_pa*) handle.api;
    retval = api->server_init(kcontext, module_context, realmnames);
    return retval;
}
void
plugin_server_fini(plhandle handle, krb5_context kcontext, void *module_context)
{
    plugin_pa* api = (plugin_pa*) handle.api;
    api->server_fini(kcontext, module_context);
    return;
}