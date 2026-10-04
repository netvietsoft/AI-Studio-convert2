// Function: sub_56B1C4
// RVA: 0x56b1c4, Size: 156 bytes
int64_t sub_56B1C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    vsnprintf(...); // call PLT API at 0x56b238
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x56b25c
}
