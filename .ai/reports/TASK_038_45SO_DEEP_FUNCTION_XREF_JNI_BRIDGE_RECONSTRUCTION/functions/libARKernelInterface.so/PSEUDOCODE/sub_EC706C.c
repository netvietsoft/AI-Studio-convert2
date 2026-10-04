// Function: sub_EC706C
// RVA: 0xec706c, Size: 516 bytes
int64_t sub_EC706C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call PLT API at 0xec7148
    return a0;
    sub_EB7040(...); // call internal at 0xec7210
    sub_EB7040(...); // call internal at 0xec723c
    memcpy(...); // call PLT API at 0xec725c
    __stack_chk_fail(...); // call PLT API at 0xec726c
}
