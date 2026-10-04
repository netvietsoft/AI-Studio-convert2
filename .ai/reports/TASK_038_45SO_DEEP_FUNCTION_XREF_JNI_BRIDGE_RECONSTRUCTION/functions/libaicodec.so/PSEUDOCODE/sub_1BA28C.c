// Function: sub_1BA28C
// RVA: 0x1ba28c, Size: 376 bytes
int64_t sub_1BA28C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba350
    __memcpy_chk(...); // call imported API via PLT at 0x1ba370
    __memcpy_chk(...); // call imported API via PLT at 0x1ba384
    memcpy(...); // call imported API via PLT at 0x1ba3c8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba400
}
