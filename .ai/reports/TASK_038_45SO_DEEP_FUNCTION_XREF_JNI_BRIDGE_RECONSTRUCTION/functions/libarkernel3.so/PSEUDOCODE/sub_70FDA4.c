// Function: sub_70FDA4
// RVA: 0x70fda4, Size: 184 bytes
int64_t sub_70FDA4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call PLT API at 0x70fdd8
    wgpuTextureGetHeight(...); // call PLT API at 0x70fde4
    sub_9FE580(...); // call internal at 0x70fe1c
    wgpuCommandEncoderCopyTextureToTexture(...); // call PLT API at 0x70fe2c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x70fe58
}
