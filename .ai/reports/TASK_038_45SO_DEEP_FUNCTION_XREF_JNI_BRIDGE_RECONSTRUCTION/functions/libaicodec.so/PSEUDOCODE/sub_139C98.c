// Function: sub_139C98
// RVA: 0x139c98, Size: 152 bytes
int64_t sub_139C98(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call imported API via PLT at 0x139d08
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x139d2c
}
