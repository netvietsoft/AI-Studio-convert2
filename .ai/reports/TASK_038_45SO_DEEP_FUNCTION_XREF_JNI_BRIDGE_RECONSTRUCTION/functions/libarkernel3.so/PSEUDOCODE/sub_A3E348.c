// Function: sub_A3E348
// RVA: 0xa3e348, Size: 188 bytes
int64_t sub_A3E348(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vldp_get_data_protocol_ar_device_data(...); // call PLT API at 0xa3e370
    vldp_get_ardevice_data_pointer_ref(...); // call PLT API at 0xa3e378
    vldp_get_ardevice_data_data_source_type(...); // call PLT API at 0xa3e384
    vldp_get_ardevice_data_augmented_reality_projection_matrix(...); // call PLT API at 0xa3e39c
    vldp_get_ardevice_data_augmented_reality_view_matrix(...); // call PLT API at 0xa3e3c0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa3e400
}
