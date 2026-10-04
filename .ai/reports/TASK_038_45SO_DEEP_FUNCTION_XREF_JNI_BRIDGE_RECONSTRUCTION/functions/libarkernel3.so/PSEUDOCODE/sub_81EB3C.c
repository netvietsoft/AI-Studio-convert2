// Function: sub_81EB3C
// RVA: 0x81eb3c, Size: 260 bytes
int64_t sub_81EB3C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureRelease(...); // call imported API via PLT at 0x81eb6c
    wgpuTextureViewRelease(...); // call imported API via PLT at 0x81eb7c
    sub_821B54(...); // call internal func at 0x81ebb8
    (*x8)(...); // indirect call at 0x81ebe0
    (*x8)(...); // indirect call at 0x81ec08
    sub_64C158(...); // call internal func at 0x81ec1c
    _ZdlPv(...); // call imported API via PLT at 0x81ec24
    return a0;
}
