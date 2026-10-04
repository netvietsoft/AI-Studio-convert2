// Function: sub_4B1A04
// RVA: 0x4b1a04, Size: 148 bytes
int64_t sub_4B1A04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call PLT API at 0x4b1a70
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x4b1a94
}
