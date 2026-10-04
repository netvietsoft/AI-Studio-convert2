// Function: sub_B8E42C
// RVA: 0xb8e42c, Size: 176 bytes
int64_t sub_B8E42C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xb8e468
    malloc(...); // call PLT API at 0xb8e480
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xb8e4b8
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xb8e4c0
    __cxa_throw(...); // call PLT API at 0xb8e4d8
}
