// Function: sub_BA40A4
// RVA: 0xba40a4, Size: 376 bytes
int64_t sub_BA40A4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xba4128
    sub_BA22EC(...); // call internal at 0xba4168
    free(...); // call PLT API at 0xba417c
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xba41b4
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xba41cc
    __cxa_throw(...); // call PLT API at 0xba41e4
    free(...); // call PLT API at 0xba41fc
    sub_106B814(...); // call internal at 0xba4214
    __stack_chk_fail(...); // call PLT API at 0xba4218
}
