// Function: sub_8128C
// RVA: 0x8128c, Size: 84 bytes
int64_t sub_8128C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    clock_gettime(...); // call imported API via PLT at 0x812a0
    return a0;
    __errno(...); // call imported API via PLT at 0x812c8
    const char* s_49560 = "clock_gettime(CLOCK_MONOTONIC) failed"; // string xref
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call imported API via PLT at 0x812d8
    sub_754CC(...); // call internal func at 0x812dc
}
