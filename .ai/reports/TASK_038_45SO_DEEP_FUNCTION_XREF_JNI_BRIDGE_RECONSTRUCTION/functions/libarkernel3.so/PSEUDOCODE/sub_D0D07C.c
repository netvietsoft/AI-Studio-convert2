// Function: sub_D0D07C
// RVA: 0xd0d07c, Size: 128 bytes
int64_t sub_D0D07C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call PLT API at 0xd0d0d0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd0d0f8
}
