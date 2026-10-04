// Function: sub_BB28CC
// RVA: 0xbb28cc, Size: 376 bytes
int64_t sub_BB28CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xbb2950
    sub_BB2A44(...); // call internal at 0xbb2990
    free(...); // call PLT API at 0xbb29a4
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xbb29dc
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xbb29f4
    __cxa_throw(...); // call PLT API at 0xbb2a0c
    free(...); // call PLT API at 0xbb2a24
    sub_106B814(...); // call internal at 0xbb2a3c
    __stack_chk_fail(...); // call PLT API at 0xbb2a40
}
