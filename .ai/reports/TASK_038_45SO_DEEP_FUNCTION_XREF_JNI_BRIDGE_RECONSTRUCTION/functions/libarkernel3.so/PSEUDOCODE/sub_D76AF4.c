// Function: sub_D76AF4
// RVA: 0xd76af4, Size: 156 bytes
int64_t sub_D76AF4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s[%u]";
    vsnprintf(...); // call PLT API at 0xd76b68
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd76b8c
}
