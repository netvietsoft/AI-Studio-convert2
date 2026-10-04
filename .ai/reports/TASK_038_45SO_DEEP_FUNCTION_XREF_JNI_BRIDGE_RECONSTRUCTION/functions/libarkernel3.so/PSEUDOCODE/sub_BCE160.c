// Function: sub_BCE160
// RVA: 0xbce160, Size: 132 bytes
int64_t sub_BCE160(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuCommandEncoderFinish(...); // call PLT API at 0xbce190
    wgpuQueueSubmit(...); // call PLT API at 0xbce1a8
    wgpuCommandBufferRelease(...); // call PLT API at 0xbce1b0
    wgpuCommandEncoderRelease(...); // call PLT API at 0xbce1b8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbce1e0
}
