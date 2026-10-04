// Function: sub_BAD8D0
// RVA: 0xbad8d0, Size: 212 bytes
int64_t sub_BAD8D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_BBADB4(...); // call internal at 0xbad920
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbad9a0
}
