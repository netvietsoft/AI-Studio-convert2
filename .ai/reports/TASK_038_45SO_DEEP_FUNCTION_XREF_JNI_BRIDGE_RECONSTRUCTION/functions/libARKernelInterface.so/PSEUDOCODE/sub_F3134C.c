// Function: sub_F3134C
// RVA: 0xf3134c, Size: 172 bytes
int64_t sub_F3134C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xf31380
    malloc(...); // call PLT API at 0xf3139c
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf313d4
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf313dc
    __cxa_throw(...); // call PLT API at 0xf313f4
}
