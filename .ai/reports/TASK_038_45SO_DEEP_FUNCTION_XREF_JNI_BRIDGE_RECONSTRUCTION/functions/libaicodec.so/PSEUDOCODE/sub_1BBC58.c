// Function: sub_1BBC58
// RVA: 0x1bbc58, Size: 204 bytes
int64_t sub_1BBC58(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bbcd4
    memcpy(...); // call imported API via PLT at 0x1bbcf4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bbd20
}
