// Function: sub_7870A4
// RVA: 0x7870a4, Size: 184 bytes
int64_t sub_7870A4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x7870d8
    wgpuTextureGetHeight(...); // call PLT API at 0x7870e4
    sub_9FE580(...); // call internal at 0x78711c
    wgpuCommandEncoderCopyTextureToTexture(...); // call PLT API at 0x78712c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x787158
}
