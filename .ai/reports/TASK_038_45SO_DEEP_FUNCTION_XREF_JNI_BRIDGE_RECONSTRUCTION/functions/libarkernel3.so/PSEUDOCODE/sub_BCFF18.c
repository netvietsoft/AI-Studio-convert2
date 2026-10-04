// Function: sub_BCFF18
// RVA: 0xbcff18, Size: 172 bytes
int64_t sub_BCFF18(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuBufferGetMapState(...); // call PLT API at 0xbcff3c
    wgpuBufferMapAsync(...); // call PLT API at 0xbcff78
    sched_yield(...); // call PLT API at 0xbcff84
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbcffbc
    sub_562D14(...); // call internal at 0xbcffc0
}
