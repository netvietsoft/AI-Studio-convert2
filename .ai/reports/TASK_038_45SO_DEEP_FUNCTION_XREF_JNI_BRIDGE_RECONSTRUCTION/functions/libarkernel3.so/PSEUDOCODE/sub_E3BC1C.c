// Function: sub_E3BC1C
// RVA: 0xe3bc1c, Size: 156 bytes
int64_t sub_E3BC1C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    vsnprintf(...); // call PLT API at 0xe3bc90
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3bcb4
}
