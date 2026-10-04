// Function: sub_9BC0B4
// RVA: 0x9bc0b4, Size: 140 bytes
int64_t sub_9BC0B4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureCreateView(...); // call PLT API at 0x9bc0e0
    sub_9FE4F4(...); // call internal at 0x9bc10c
    wgpuTextureViewRelease(...); // call PLT API at 0x9bc114
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x9bc13c
}
