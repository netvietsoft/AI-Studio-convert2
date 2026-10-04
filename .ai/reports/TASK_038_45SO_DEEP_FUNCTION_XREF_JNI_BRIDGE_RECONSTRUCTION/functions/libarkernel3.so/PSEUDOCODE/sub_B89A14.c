// Function: sub_B89A14
// RVA: 0xb89a14, Size: 164 bytes
int64_t sub_B89A14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%.14g";
    __vsprintf_chk(...); // call PLT API at 0xb89a90
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb89ab4
}
