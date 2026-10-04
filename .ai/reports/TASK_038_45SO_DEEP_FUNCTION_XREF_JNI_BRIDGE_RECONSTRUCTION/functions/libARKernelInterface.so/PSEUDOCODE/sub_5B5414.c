// Function: sub_5B5414
// RVA: 0x5b5414, Size: 228 bytes
int64_t sub_5B5414(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0x5b5490
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x5b54b4
    malloc(...); // call PLT API at 0x5b54b8
    free(...); // call PLT API at 0x5b54bc
    __cxa_atexit(...); // call PLT API at 0x5b54ec
    sub_5B603C(...); // call internal at 0x5b54f4
}
