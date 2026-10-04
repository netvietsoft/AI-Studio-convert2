// Function: sub_943840
// RVA: 0x943840, Size: 228 bytes
int64_t sub_943840(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureRelease(...); // call PLT API at 0x943884
    wgpuTextureViewRelease(...); // call PLT API at 0x943894
    sub_A7FC40(...); // call internal at 0x9438d8
    sub_A81778(...); // call internal at 0x9438dc
    wgpuDeviceCreateTexture(...); // call PLT API at 0x9438e4
    wgpuTextureCreateView(...); // call PLT API at 0x9438f0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x943920
}
