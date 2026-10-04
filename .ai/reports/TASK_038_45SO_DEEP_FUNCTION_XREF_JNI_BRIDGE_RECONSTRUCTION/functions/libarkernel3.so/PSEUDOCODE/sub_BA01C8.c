// Function: sub_BA01C8
// RVA: 0xba01c8, Size: 168 bytes
int64_t sub_BA01C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xba01fc
    malloc(...); // call PLT API at 0xba0214
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xba024c
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xba0254
    __cxa_throw(...); // call PLT API at 0xba026c
}
