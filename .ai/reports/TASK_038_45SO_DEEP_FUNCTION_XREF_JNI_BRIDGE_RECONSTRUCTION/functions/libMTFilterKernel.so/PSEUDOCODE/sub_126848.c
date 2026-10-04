// Function: sub_126848
// RVA: 0x126848, Size: 164 bytes
int64_t sub_126848(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s%s";
    __vsprintf_chk(...); // call PLT API at 0x1268c4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1268e8
}
