// Function: sub_12D910
// RVA: 0x12d910, Size: 164 bytes
int64_t sub_12D910(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s%s";
    __vsprintf_chk(...); // call PLT API at 0x12d98c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12d9b0
}
