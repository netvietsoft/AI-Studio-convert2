// Function: sub_923464
// RVA: 0x923464, Size: 128 bytes
int64_t sub_923464(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureReference(...); // call imported API via PLT at 0x923488
    wgpuTextureRelease(...); // call imported API via PLT at 0x923498
    wgpuTextureViewRelease(...); // call imported API via PLT at 0x9234a4
    wgpuTextureCreateView(...); // call imported API via PLT at 0x9234b4
    return a0;
}
