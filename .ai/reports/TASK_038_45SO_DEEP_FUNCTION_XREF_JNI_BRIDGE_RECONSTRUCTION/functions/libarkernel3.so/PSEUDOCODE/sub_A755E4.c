// Function: sub_A755E4
// RVA: 0xa755e4, Size: 164 bytes
int64_t sub_A755E4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsnprintf_chk(...); // call PLT API at 0xa75660
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa75684
}
