// Function: sub_BA4F8C
// RVA: 0xba4f8c, Size: 176 bytes
int64_t sub_BA4F8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xba4fc8
    malloc(...); // call PLT API at 0xba4fe0
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xba5018
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xba5020
    __cxa_throw(...); // call PLT API at 0xba5038
}
