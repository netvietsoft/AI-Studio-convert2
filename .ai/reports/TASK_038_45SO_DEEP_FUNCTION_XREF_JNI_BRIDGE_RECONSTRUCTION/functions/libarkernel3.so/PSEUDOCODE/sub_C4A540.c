// Function: sub_C4A540
// RVA: 0xc4a540, Size: 164 bytes
int64_t sub_C4A540(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call PLT API at 0xc4a5bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc4a5e0
}
