// Function: sub_6EE0E4
// RVA: 0x6ee0e4, Size: 768 bytes
int64_t sub_6EE0E4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentContext(...); // call PLT API at 0x6ee114
    eglGetCurrentDisplay(...); // call PLT API at 0x6ee124
    eglGetCurrentContext(...); // call PLT API at 0x6ee260
    eglGetCurrentDisplay(...); // call PLT API at 0x6ee268
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x6ee294
    eglGetCurrentContext(...); // call PLT API at 0x6ee370
    eglGetCurrentDisplay(...); // call PLT API at 0x6ee378
    fprintf(...); // call PLT API at 0x6ee3a0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x6ee3e0
}
