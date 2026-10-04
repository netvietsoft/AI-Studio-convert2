// Function: sub_B7D174
// RVA: 0xb7d174, Size: 156 bytes
int64_t sub_B7D174(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    setjmp(...); // call PLT API at 0xb7d1c0
    (*x20)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb7d20c
}
