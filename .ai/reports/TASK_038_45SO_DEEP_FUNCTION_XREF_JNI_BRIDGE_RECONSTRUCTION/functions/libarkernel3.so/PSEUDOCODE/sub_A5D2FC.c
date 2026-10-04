// Function: sub_A5D2FC
// RVA: 0xa5d2fc, Size: 152 bytes
int64_t sub_A5D2FC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureReference(...); // call PLT API at 0xa5d31c
    wgpuTextureViewRelease(...); // call PLT API at 0xa5d328
    wgpuTextureRelease(...); // call PLT API at 0xa5d338
    wgpuTextureGetFormat(...); // call PLT API at 0xa5d354
    wgpuTextureGetWidth(...); // call PLT API at 0xa5d360
    wgpuTextureGetHeight(...); // call PLT API at 0xa5d36c
    wgpuTextureCreateView(...); // call PLT API at 0xa5d37c
    return a0;
}
