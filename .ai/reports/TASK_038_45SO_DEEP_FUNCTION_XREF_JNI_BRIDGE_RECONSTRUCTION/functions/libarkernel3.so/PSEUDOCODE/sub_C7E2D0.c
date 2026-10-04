// Function: sub_C7E2D0
// RVA: 0xc7e2d0, Size: 184 bytes
int64_t sub_C7E2D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call PLT API at 0xc7e328
    sub_C7DE64(...); // call internal at 0xc7e33c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc7e384
}
