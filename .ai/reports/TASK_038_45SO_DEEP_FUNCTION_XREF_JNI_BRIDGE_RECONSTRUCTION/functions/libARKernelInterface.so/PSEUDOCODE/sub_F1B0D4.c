// Function: sub_F1B0D4
// RVA: 0xf1b0d4, Size: 164 bytes
int64_t sub_F1B0D4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%p";
    __vsprintf_chk(...); // call PLT API at 0xf1b150
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf1b174
}
