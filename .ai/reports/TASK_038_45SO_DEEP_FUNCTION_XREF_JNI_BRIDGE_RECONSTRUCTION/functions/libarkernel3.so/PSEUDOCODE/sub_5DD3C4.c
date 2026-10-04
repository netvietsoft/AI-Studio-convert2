// Function: sub_5DD3C4
// RVA: 0x5dd3c4, Size: 176 bytes
int64_t sub_5DD3C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0x5dd400
    malloc(...); // call PLT API at 0x5dd418
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0x5dd450
    _ZNSt9bad_allocC1Ev(...); // call PLT API at 0x5dd458
    __cxa_throw(...); // call PLT API at 0x5dd470
}
