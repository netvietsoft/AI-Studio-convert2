// Function: sub_8EBCE8
// RVA: 0x8ebce8, Size: 164 bytes
int64_t sub_8EBCE8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s%01d.%s";
    __vsnprintf_chk(...); // call PLT API at 0x8ebd64
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8ebd88
}
