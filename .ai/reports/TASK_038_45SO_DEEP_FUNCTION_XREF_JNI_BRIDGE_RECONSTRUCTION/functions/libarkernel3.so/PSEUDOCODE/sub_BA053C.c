// Function: sub_BA053C
// RVA: 0xba053c, Size: 168 bytes
int64_t sub_BA053C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xba0570
    malloc(...); // call PLT API at 0xba0588
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xba05c0
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xba05c8
    __cxa_throw(...); // call PLT API at 0xba05e0
}
