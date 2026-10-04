// Function: sub_A40F14
// RVA: 0xa40f14, Size: 164 bytes
int64_t sub_A40F14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0xa40f90
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa40fb4
}
