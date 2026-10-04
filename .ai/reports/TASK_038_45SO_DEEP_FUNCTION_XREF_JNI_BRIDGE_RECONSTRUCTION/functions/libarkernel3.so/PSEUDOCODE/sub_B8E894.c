// Function: sub_B8E894
// RVA: 0xb8e894, Size: 168 bytes
int64_t sub_B8E894(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xb8e8c8
    malloc(...); // call PLT API at 0xb8e8e0
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xb8e918
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xb8e920
    __cxa_throw(...); // call PLT API at 0xb8e938
}
