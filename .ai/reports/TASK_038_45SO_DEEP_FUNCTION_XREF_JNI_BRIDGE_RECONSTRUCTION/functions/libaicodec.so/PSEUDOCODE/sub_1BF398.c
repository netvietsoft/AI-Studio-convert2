// Function: sub_1BF398
// RVA: 0x1bf398, Size: 316 bytes
int64_t sub_1BF398(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bf44c
    __memcpy_chk(...); // call imported API via PLT at 0x1bf460
    memcpy(...); // call imported API via PLT at 0x1bf48c
    memcpy(...); // call imported API via PLT at 0x1bf49c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bf4d0
}
