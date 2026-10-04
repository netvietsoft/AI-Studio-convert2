// Function: sub_EF10F8
// RVA: 0xef10f8, Size: 164 bytes
int64_t sub_EF10F8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call PLT API at 0xef1174
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xef1198
}
