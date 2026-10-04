// Function: sub_6B2364
// RVA: 0x6b2364, Size: 80 bytes
int64_t sub_6B2364(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuBufferRelease(...); // call imported API via PLT at 0x6b237c
    wgpuBufferRelease(...); // call imported API via PLT at 0x6b2388
    (*x8)(...); // indirect call at 0x6b239c
    return a0;
}
