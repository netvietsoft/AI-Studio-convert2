// Function: sub_E3109C
// RVA: 0xe3109c, Size: 164 bytes
int64_t sub_E3109C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%.*f";
    __vsprintf_chk(...); // call PLT API at 0xe31118
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3113c
}
