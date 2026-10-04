// Function: sub_C6F9C4
// RVA: 0xc6f9c4, Size: 164 bytes
int64_t sub_C6F9C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call PLT API at 0xc6fa40
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc6fa64
}
