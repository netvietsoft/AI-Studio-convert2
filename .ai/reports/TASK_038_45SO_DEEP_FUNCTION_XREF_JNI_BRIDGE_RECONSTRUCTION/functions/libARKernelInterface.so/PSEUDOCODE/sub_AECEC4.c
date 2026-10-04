// Function: sub_AECEC4
// RVA: 0xaecec4, Size: 164 bytes
int64_t sub_AECEC4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsprintf_chk(...); // call PLT API at 0xaecf40
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaecf64
}
