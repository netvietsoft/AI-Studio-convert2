// Function: sub_1EC688
// RVA: 0x1ec688, Size: 928 bytes
int64_t sub_1EC688(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ec80c
    memcpy(...); // call imported API via PLT at 0x1ec854
    sub_1EC688(...); // call internal func at 0x1ec85c
    memcpy(...); // call imported API via PLT at 0x1ec9d4
    __stack_chk_fail(...); // call imported API via PLT at 0x1ec9ec
    return a0;
}
