// Function: sub_1BDB1C
// RVA: 0x1bdb1c, Size: 252 bytes
int64_t sub_1BDB1C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bdbac
    memcpy(...); // call imported API via PLT at 0x1bdbd4
    memcpy(...); // call imported API via PLT at 0x1bdbe4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bdc14
}
