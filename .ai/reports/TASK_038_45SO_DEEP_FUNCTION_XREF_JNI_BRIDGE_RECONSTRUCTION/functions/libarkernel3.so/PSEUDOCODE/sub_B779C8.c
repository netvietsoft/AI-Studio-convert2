// Function: sub_B779C8
// RVA: 0xb779c8, Size: 220 bytes
int64_t sub_B779C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0xb77a44
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb77a68
    malloc(...); // call PLT API at 0xb77a6c
    free(...); // call PLT API at 0xb77a70
    __cxa_atexit(...); // call PLT API at 0xb77aa0
}
