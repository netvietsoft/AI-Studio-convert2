// Function: sub_E3BF74
// RVA: 0xe3bf74, Size: 360 bytes
int64_t sub_E3BF74(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureRelease(...); // call PLT API at 0xe3bfcc
    wgpuTextureViewRelease(...); // call PLT API at 0xe3bfdc
    sub_D7C64C(...); // call internal at 0xe3bfe4
    sub_D7D420(...); // call internal at 0xe3bfe8
    const char* str = "Texture::create";
    log2(...); // call PLT API at 0xe3c068
    sub_E16CF0(...); // call internal at 0xe3c090
    wgpuDeviceCreateTexture(...); // call PLT API at 0xe3c098
    wgpuTextureCreateView(...); // call PLT API at 0xe3c0a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3c0d8
}
