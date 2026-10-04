// Function: sub_A5AF04
// RVA: 0xa5af04, Size: 124 bytes
int64_t sub_A5AF04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureGetWidth(...); // call imported API via PLT at 0xa5af50
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xa5af7c
}
