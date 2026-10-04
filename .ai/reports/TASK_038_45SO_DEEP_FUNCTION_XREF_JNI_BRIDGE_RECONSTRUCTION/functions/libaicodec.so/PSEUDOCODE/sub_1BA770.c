// Function: sub_1BA770
// RVA: 0x1ba770, Size: 248 bytes
int64_t sub_1BA770(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba7fc
    __memcpy_chk(...); // call imported API via PLT at 0x1ba810
    memcpy(...); // call imported API via PLT at 0x1ba834
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba864
}
