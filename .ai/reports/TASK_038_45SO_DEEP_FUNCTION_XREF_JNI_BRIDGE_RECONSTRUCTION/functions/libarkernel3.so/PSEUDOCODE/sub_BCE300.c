// Function: sub_BCE300
// RVA: 0xbce300, Size: 156 bytes
int64_t sub_BCE300(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuDeviceCreateBuffer(...); // call PLT API at 0xbce348
    wgpuQueueWriteBuffer(...); // call PLT API at 0xbce368
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbce398
}
