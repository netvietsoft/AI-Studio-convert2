// Function: sub_1BA678
// RVA: 0x1ba678, Size: 248 bytes
int64_t sub_1BA678(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba704
    __memcpy_chk(...); // call imported API via PLT at 0x1ba718
    memcpy(...); // call imported API via PLT at 0x1ba73c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba76c
}
