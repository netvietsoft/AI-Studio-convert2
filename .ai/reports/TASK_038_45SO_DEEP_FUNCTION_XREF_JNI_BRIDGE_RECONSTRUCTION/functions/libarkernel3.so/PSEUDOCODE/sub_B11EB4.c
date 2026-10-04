// Function: sub_B11EB4
// RVA: 0xb11eb4, Size: 624 bytes
int64_t sub_B11EB4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B12124(...); // call internal at 0xb11f08
    sub_B12124(...); // call internal at 0xb11f60
    wgpuDeviceCreateCommandEncoder(...); // call PLT API at 0xb11f74
    wgpuTextureGetWidth(...); // call PLT API at 0xb11f80
    wgpuTextureGetHeight(...); // call PLT API at 0xb11f8c
    sub_B11978(...); // call internal at 0xb11fb4
    wgpuCommandEncoderCopyTextureToTexture(...); // call PLT API at 0xb11fe8
    wgpuCommandEncoderFinish(...); // call PLT API at 0xb11ff4
    wgpuQueueSubmit(...); // call PLT API at 0xb1200c
    wgpuCommandEncoderRelease(...); // call PLT API at 0xb12014
    wgpuCommandBufferRelease(...); // call PLT API at 0xb1201c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb12120
}
