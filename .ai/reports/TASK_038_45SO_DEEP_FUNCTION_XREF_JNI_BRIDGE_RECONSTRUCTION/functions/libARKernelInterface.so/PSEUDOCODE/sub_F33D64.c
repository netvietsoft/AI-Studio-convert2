// Function: sub_F33D64
// RVA: 0xf33d64, Size: 404 bytes
int64_t sub_F33D64(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xf33e00
    sub_F33EF8(...); // call internal at 0xf33e44
    free(...); // call PLT API at 0xf33e58
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xf33e90
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xf33ea8
    __cxa_throw(...); // call PLT API at 0xf33ec0
    free(...); // call PLT API at 0xf33ed8
    sub_1042BE4(...); // call internal at 0xf33ef0
    __stack_chk_fail(...); // call PLT API at 0xf33ef4
}
