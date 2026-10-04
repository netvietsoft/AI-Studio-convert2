// Function: sub_FB1048
// RVA: 0xfb1048, Size: 156 bytes
int64_t sub_FB1048(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s.%s";
    vsnprintf(...); // call PLT API at 0xfb10bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb10e0
}
