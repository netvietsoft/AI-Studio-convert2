// Function: sub_AF5BD8
// RVA: 0xaf5bd8, Size: 164 bytes
int64_t sub_AF5BD8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsprintf_chk(...); // call PLT API at 0xaf5c54
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xaf5c78
}
