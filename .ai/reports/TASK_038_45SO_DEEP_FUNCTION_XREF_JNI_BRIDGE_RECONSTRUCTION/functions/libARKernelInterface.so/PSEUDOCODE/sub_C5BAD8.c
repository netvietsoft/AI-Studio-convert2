// Function: sub_C5BAD8
// RVA: 0xc5bad8, Size: 156 bytes
int64_t sub_C5BAD8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s.%s";
    vsnprintf(...); // call PLT API at 0xc5bb4c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc5bb70
}
