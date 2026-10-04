// Function: sub_A76A8C
// RVA: 0xa76a8c, Size: 272 bytes
int64_t sub_A76A8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_CC4F30(...); // call internal at 0xa76ad0
    wgpuDeviceCreateCommandEncoder(...); // call PLT API at 0xa76af0
    sub_A76B9C(...); // call internal at 0xa76b0c
    wgpuCommandEncoderFinish(...); // call PLT API at 0xa76b1c
    wgpuQueueSubmit(...); // call PLT API at 0xa76b34
    wgpuCommandEncoderRelease(...); // call PLT API at 0xa76b3c
    wgpuCommandBufferRelease(...); // call PLT API at 0xa76b44
    return a0;
    sub_CC451C(...); // call internal at 0xa76b78
    sub_CC451C(...); // call internal at 0xa76b88
    __stack_chk_fail(...); // call PLT API at 0xa76b94
    sub_562D14(...); // call internal at 0xa76b98
}
