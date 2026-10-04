// Function: sub_102AF7C
// RVA: 0x102af7c, Size: 164 bytes
int64_t sub_102AF7C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%hd";
    __vsprintf_chk(...); // call PLT API at 0x102aff8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x102b01c
}
