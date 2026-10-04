// Function: sub_EE9F14
// RVA: 0xee9f14, Size: 700 bytes
int64_t sub_EE9F14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EEA1D0(...); // call internal at 0xeea07c
    memmove(...); // call PLT API at 0xeea154
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xeea1cc
}
