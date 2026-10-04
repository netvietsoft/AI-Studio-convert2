// Function: sub_8A171C
// RVA: 0x8a171c, Size: 308 bytes
int64_t sub_8A171C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk111__call_onceERVmPvPFvS2_E(...); // call PLT API at 0x8a17a0
    sub_33AD18(...); // call internal at 0x8a17b0
    return a0;
    sub_33ACE0(...); // call internal at 0x8a17fc
    __stack_chk_fail(...); // call PLT API at 0x8a1800
    __cxa_guard_acquire(...); // call PLT API at 0x8a1814
    sub_33ACE0(...); // call internal at 0x8a1824
    __cxa_atexit(...); // call PLT API at 0x8a183c
    __cxa_guard_release(...); // call PLT API at 0x8a1844
}
