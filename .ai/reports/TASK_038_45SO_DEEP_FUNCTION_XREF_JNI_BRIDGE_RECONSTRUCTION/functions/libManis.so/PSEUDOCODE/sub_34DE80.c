// Function: sub_34DE80
// RVA: 0x34de80, Size: 1560 bytes
int64_t sub_34DE80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    setenv(...); // call PLT API at 0x34deb0
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x34e1a0
    fprintf(...); // call PLT API at 0x34e45c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x34e494
}
