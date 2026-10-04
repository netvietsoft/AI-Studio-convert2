// Function: sub_F3161C
// RVA: 0xf3161c, Size: 172 bytes
int64_t sub_F3161C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xf31650
    malloc(...); // call PLT API at 0xf3166c
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf316a4
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf316ac
    __cxa_throw(...); // call PLT API at 0xf316c4
}
