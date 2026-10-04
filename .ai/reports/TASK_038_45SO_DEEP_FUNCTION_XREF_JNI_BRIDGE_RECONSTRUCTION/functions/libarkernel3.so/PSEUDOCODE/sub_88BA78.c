// Function: sub_88BA78
// RVA: 0x88ba78, Size: 248 bytes
int64_t sub_88BA78(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x88babc
    wgpuTextureGetHeight(...); // call PLT API at 0x88bacc
    wgpuTextureViewRelease(...); // call PLT API at 0x88baf0
    wgpuTextureRelease(...); // call PLT API at 0x88bafc
    sub_A7FC40(...); // call internal at 0x88bb28
    sub_A81778(...); // call internal at 0x88bb2c
    wgpuDeviceCreateTexture(...); // call PLT API at 0x88bb34
    wgpuTextureCreateView(...); // call PLT API at 0x88bb40
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x88bb6c
}
