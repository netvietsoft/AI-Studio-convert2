// Function: sub_F9E30
// RVA: 0xf9e30, Size: 164 bytes
int64_t sub_F9E30(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s%s";
    __vsprintf_chk(...); // call PLT API at 0xf9eac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf9ed0
}
