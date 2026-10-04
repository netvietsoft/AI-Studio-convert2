// Function: sub_B7BE90
// RVA: 0xb7be90, Size: 348 bytes
int64_t sub_B7BE90(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B7BFEC(...); // call internal at 0xb7bf00
    free(...); // call PLT API at 0xb7bf40
    _Znwm(...); // call PLT API at 0xb7bf54
    malloc(...); // call PLT API at 0xb7bf60
    _Znwm(...); // call PLT API at 0xb7bf7c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb7bfe8
}
