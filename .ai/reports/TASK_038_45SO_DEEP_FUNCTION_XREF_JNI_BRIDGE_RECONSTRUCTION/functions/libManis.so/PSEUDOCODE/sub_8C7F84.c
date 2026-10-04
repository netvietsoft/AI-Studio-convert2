// Function: sub_8C7F84
// RVA: 0x8c7f84, Size: 676 bytes
int64_t sub_8C7F84(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x8c80f0
    fprintf(...); // call PLT API at 0x8c81f4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8c8224
}
