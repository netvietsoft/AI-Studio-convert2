// Function: sub_D97188
// RVA: 0xd97188, Size: 164 bytes
int64_t sub_D97188(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%.*f";
    __vsprintf_chk(...); // call PLT API at 0xd97204
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd97228
}
