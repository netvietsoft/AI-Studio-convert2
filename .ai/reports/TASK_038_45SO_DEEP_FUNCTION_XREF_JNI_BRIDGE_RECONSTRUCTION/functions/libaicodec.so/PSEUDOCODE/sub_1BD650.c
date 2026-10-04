// Function: sub_1BD650
// RVA: 0x1bd650, Size: 204 bytes
int64_t sub_1BD650(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd6bc
    memcpy(...); // call imported API via PLT at 0x1bd6ec
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd718
}
