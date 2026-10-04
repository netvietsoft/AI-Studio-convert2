// Function: sub_7F9AA8
// RVA: 0x7f9aa8, Size: 164 bytes
int64_t sub_7F9AA8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsprintf_chk(...); // call PLT API at 0x7f9b24
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7f9b48
}
