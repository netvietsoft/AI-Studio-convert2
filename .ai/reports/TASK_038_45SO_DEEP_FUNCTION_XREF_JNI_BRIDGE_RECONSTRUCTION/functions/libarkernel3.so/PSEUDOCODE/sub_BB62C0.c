// Function: sub_BB62C0
// RVA: 0xbb62c0, Size: 400 bytes
int64_t sub_BB62C0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call PLT API at 0xbb6350
    sub_BB6450(...); // call internal at 0xbb639c
    free(...); // call PLT API at 0xbb63b4
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xbb63e8
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xbb6400
    __cxa_throw(...); // call PLT API at 0xbb6418
    free(...); // call PLT API at 0xbb6430
    sub_106B814(...); // call internal at 0xbb6448
    __stack_chk_fail(...); // call PLT API at 0xbb644c
}
