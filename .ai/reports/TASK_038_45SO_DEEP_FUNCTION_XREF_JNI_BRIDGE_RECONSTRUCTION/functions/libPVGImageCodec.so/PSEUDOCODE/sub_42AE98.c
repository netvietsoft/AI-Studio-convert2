// Function: sub_42AE98
// RVA: 0x42ae98, Size: 128 bytes
int64_t sub_42AE98(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call PLT API at 0x42aeec
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x42af14
}
