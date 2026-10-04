// Function: sub_94F73C
// RVA: 0x94f73c, Size: 176 bytes
int64_t sub_94F73C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "/dev/urandom";
    __emutls_get_address(...); // call PLT API at 0x94f788
    _ZNSt6__ndk113random_deviceC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE(...); // call PLT API at 0x94f790
    _ZdlPv(...); // call PLT API at 0x94f7a0
    __emutls_get_address(...); // call PLT API at 0x94f7ac
    __cxa_thread_atexit(...); // call PLT API at 0x94f7c4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x94f7e8
}
