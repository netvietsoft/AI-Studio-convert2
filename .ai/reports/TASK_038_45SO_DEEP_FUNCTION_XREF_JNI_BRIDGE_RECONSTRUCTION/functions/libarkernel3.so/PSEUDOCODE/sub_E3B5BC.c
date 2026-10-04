// Function: sub_E3B5BC
// RVA: 0xe3b5bc, Size: 296 bytes
int64_t sub_E3B5BC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "Texture::create";
    wgpuTextureRelease(...); // call PLT API at 0xe3b668
    wgpuTextureViewRelease(...); // call PLT API at 0xe3b678
    wgpuTextureViewRelease(...); // call PLT API at 0xe3b688
    wgpuTextureCreateView(...); // call PLT API at 0xe3b69c
    wgpuTextureCreateView(...); // call PLT API at 0xe3b6ac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3b6e0
}
