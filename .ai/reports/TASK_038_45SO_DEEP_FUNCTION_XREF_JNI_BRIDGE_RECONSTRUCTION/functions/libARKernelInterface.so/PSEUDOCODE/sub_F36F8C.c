// Function: sub_F36F8C
// RVA: 0xf36f8c, Size: 404 bytes
int64_t sub_F36F8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xf37028
    sub_F33EF8(...); // call internal at 0xf3706c
    free(...); // call PLT API at 0xf37080
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf370b8
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf370d0
    __cxa_throw(...); // call PLT API at 0xf370e8
    free(...); // call PLT API at 0xf37100
    sub_1042BE4(...); // call internal at 0xf37118
    __stack_chk_fail(...); // call PLT API at 0xf3711c
}
