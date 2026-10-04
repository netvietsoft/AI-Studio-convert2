// Function: sub_A596B4
// RVA: 0xa596b4, Size: 436 bytes
int64_t sub_A596B4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vldp_get_texture_width(...); // call PLT API at 0xa596ec
    vldp_get_texture_height(...); // call PLT API at 0xa596f8
    vldp_get_texture_format(...); // call PLT API at 0xa59714
    vldp_get_texture_metal_handle(...); // call PLT API at 0xa59770
    sub_A2FDF4(...); // call internal at 0xa59794
    vldp_get_texture_opengl_handle(...); // call PLT API at 0xa597ac
    vldp_get_texture_d3d11_handle(...); // call PLT API at 0xa597e8
    wgpuDeviceCreateTexture(...); // call PLT API at 0xa59810
    wgpuTextureCreateView(...); // call PLT API at 0xa5981c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa59860
    sub_562D14(...); // call internal at 0xa59864
}
