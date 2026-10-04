// Function: sub_7B2A7C
// RVA: 0x7b2a7c, Size: 184 bytes
int64_t sub_7B2A7C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x7b2ab0
    wgpuTextureGetHeight(...); // call PLT API at 0x7b2abc
    sub_9FE580(...); // call internal at 0x7b2af4
    wgpuCommandEncoderCopyTextureToTexture(...); // call PLT API at 0x7b2b04
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7b2b30
}
