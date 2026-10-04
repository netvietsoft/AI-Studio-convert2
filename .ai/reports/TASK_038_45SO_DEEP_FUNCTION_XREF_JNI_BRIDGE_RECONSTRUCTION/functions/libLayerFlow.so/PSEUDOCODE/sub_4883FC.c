// Function: sub_4883FC
// RVA: 0x4883fc, Size: 112 bytes
int64_t sub_4883FC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    posix_memalign(...); // call PLT API at 0x48842c
    return a0;
    sub_4883B4(...); // call internal at 0x488464
    __stack_chk_fail(...); // call PLT API at 0x488468
}
