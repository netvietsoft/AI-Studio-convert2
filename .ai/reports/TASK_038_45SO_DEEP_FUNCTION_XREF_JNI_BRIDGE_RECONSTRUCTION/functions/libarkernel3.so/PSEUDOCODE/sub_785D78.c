// Function: sub_785D78
// RVA: 0x785d78, Size: 184 bytes
int64_t sub_785D78(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x785dac
    wgpuTextureGetHeight(...); // call PLT API at 0x785db8
    sub_9FE580(...); // call internal at 0x785df0
    wgpuCommandEncoderCopyTextureToTexture(...); // call PLT API at 0x785e00
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x785e2c
}
