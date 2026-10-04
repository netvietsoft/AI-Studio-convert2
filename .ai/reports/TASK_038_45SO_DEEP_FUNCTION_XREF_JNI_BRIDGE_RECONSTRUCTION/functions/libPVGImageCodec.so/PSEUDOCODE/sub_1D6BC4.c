// Function: sub_1D6BC4
// RVA: 0x1d6bc4, Size: 388 bytes
int64_t sub_1D6BC4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcmp(...); // call PLT API at 0x1d6bfc
    sub_1D7740(...); // call internal at 0x1d6c74
    sub_1D7740(...); // call internal at 0x1d6cac
    __stack_chk_fail(...); // call PLT API at 0x1d6d00
    return a0;
}
