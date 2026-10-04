// Function: sub_E3C0DC
// RVA: 0xe3c0dc, Size: 324 bytes
int64_t sub_E3C0DC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuSamplerRelease(...); // call PLT API at 0xe3c110
    sub_D7C64C(...); // call internal at 0xe3c114
    sub_D7D420(...); // call internal at 0xe3c118
    const char* str = "Texture::Sampler";
    sub_E16CF0(...); // call internal at 0xe3c1ec
    wgpuDeviceCreateSampler(...); // call PLT API at 0xe3c1f4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3c21c
}
