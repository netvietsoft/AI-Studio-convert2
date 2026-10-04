// Function: sub_9139A0
// RVA: 0x9139a0, Size: 220 bytes
int64_t sub_9139A0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x9139d8
    wgpuTextureGetHeight(...); // call PLT API at 0x9139ec
    sub_9136CC(...); // call internal at 0x913a00
    sub_A7FC40(...); // call internal at 0x913a34
    sub_A81778(...); // call internal at 0x913a38
    wgpuDeviceCreateTexture(...); // call PLT API at 0x913a40
    wgpuTextureCreateView(...); // call PLT API at 0x913a4c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x913a78
}
