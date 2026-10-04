// Function: sub_A3D488
// RVA: 0xa3d488, Size: 164 bytes
int64_t sub_A3D488(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s.%s";
    __vsnprintf_chk(...); // call PLT API at 0xa3d504
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa3d528
}
