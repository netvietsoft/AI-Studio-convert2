// Function: sub_1BB5EC
// RVA: 0x1bb5ec, Size: 208 bytes
int64_t sub_1BB5EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb668
    memcpy(...); // call imported API via PLT at 0x1bb68c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb6b8
}
