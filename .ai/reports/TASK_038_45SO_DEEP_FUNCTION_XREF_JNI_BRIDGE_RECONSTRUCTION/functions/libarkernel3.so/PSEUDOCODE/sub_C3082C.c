// Function: sub_C3082C
// RVA: 0xc3082c, Size: 156 bytes
int64_t sub_C3082C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    vsnprintf(...); // call PLT API at 0xc308a0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc308c4
}
