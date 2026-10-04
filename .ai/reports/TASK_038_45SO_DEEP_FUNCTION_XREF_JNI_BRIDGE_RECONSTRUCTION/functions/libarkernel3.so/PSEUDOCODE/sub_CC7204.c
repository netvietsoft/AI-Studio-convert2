// Function: sub_CC7204
// RVA: 0xcc7204, Size: 244 bytes
int64_t sub_CC7204(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuDeviceCreateTexture(...); // call PLT API at 0xcc7278
    wgpuQueueWriteTexture(...); // call PLT API at 0xcc72c4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xcc72f4
}
