// Function: sub_1BA57C
// RVA: 0x1ba57c, Size: 252 bytes
int64_t sub_1BA57C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba60c
    __memcpy_chk(...); // call imported API via PLT at 0x1ba620
    memcpy(...); // call imported API via PLT at 0x1ba644
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba674
}
