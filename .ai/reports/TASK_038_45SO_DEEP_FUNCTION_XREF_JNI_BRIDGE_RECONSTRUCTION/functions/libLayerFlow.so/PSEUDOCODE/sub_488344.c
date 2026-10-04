// Function: sub_488344
// RVA: 0x488344, Size: 112 bytes
int64_t sub_488344(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    posix_memalign(...); // call PLT API at 0x488374
    return a0;
    sub_4883B4(...); // call internal at 0x4883ac
    __stack_chk_fail(...); // call PLT API at 0x4883b0
}
