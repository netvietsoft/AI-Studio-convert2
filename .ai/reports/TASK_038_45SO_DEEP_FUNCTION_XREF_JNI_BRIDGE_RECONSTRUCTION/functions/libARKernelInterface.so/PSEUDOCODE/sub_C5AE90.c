// Function: sub_C5AE90
// RVA: 0xc5ae90, Size: 164 bytes
int64_t sub_C5AE90(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d%c";
    __vsprintf_chk(...); // call PLT API at 0xc5af0c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc5af30
}
