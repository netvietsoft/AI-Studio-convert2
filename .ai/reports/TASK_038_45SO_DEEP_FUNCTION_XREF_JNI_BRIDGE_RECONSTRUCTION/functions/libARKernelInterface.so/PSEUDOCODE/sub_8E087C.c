// Function: sub_8E087C
// RVA: 0x8e087c, Size: 164 bytes
int64_t sub_8E087C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%f,%f,%f,%f,%f";
    __vsprintf_chk(...); // call PLT API at 0x8e08f8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8e091c
}
