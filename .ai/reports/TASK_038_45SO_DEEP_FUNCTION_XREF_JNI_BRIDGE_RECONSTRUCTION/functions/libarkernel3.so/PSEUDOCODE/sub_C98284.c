// Function: sub_C98284
// RVA: 0xc98284, Size: 164 bytes
int64_t sub_C98284(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call PLT API at 0xc98300
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc98324
}
