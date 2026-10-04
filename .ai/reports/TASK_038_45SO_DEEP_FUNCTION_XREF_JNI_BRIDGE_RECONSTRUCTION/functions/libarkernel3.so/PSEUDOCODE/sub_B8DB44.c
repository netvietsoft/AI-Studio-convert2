// Function: sub_B8DB44
// RVA: 0xb8db44, Size: 176 bytes
int64_t sub_B8DB44(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0xb8db80
    malloc(...); // call PLT API at 0xb8db98
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0xb8dbd0
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0xb8dbd8
    __cxa_throw(...); // call PLT API at 0xb8dbf0
}
