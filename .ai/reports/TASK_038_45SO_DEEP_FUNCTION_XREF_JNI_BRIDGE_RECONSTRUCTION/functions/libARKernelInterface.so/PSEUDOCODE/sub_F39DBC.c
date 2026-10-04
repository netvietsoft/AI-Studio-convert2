// Function: sub_F39DBC
// RVA: 0xf39dbc, Size: 428 bytes
int64_t sub_F39DBC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xf39e68
    sub_F39F68(...); // call internal at 0xf39eb4
    free(...); // call PLT API at 0xf39ecc
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf39f00
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf39f18
    __cxa_throw(...); // call PLT API at 0xf39f30
    free(...); // call PLT API at 0xf39f48
    sub_1042BE4(...); // call internal at 0xf39f60
    __stack_chk_fail(...); // call PLT API at 0xf39f64
}
