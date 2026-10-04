// Function: sub_BB0F0C
// RVA: 0xbb0f0c, Size: 168 bytes
int64_t sub_BB0F0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xbb0f40
    malloc(...); // call PLT API at 0xbb0f58
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xbb0f90
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xbb0f98
    __cxa_throw(...); // call PLT API at 0xbb0fb0
}
