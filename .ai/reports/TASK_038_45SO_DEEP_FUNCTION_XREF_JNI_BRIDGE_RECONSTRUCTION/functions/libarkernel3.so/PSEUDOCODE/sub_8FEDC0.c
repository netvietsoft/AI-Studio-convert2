// Function: sub_8FEDC0
// RVA: 0x8fedc0, Size: 164 bytes
int64_t sub_8FEDC0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s%05d.%s";
    __vsnprintf_chk(...); // call PLT API at 0x8fee3c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8fee60
}
