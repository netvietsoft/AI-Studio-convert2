// Function: sub_8CA35C
// RVA: 0x8ca35c, Size: 636 bytes
int64_t sub_8CA35C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x8ca4b4
    fprintf(...); // call PLT API at 0x8ca5a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8ca5d4
}
