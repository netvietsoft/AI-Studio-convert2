// Function: sub_BA6100
// RVA: 0xba6100, Size: 400 bytes
int64_t sub_BA6100(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xba6190
    sub_BA6290(...); // call internal at 0xba61dc
    free(...); // call PLT API at 0xba61f4
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xba6228
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xba6240
    __cxa_throw(...); // call PLT API at 0xba6258
    free(...); // call PLT API at 0xba6270
    sub_106B814(...); // call internal at 0xba6288
    __stack_chk_fail(...); // call PLT API at 0xba628c
}
