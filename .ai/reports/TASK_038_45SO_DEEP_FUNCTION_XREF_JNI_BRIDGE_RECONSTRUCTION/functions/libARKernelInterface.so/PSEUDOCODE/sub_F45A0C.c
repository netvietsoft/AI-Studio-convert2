// Function: sub_F45A0C
// RVA: 0xf45a0c, Size: 332 bytes
int64_t sub_F45A0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xf45a7c
    sub_F45B58(...); // call internal at 0xf45ab0
    free(...); // call PLT API at 0xf45ac4
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf45af0
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf45b08
    __cxa_throw(...); // call PLT API at 0xf45b20
    free(...); // call PLT API at 0xf45b38
    sub_1042BE4(...); // call internal at 0xf45b50
    __stack_chk_fail(...); // call PLT API at 0xf45b54
}
