// Function: sub_FCD404
// RVA: 0xfcd404, Size: 192 bytes
int64_t sub_FCD404(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xfcd438
    sub_FCDA9C(...); // call internal at 0xfcd48c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfcd4c0
}
