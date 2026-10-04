// Function: sub_FACBA0
// RVA: 0xfacba0, Size: 852 bytes
int64_t sub_FACBA0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xfaccdc
    sincosf(...); // call PLT API at 0xfaccf4
    sub_FAC970(...); // call internal at 0xfacd58
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfacef0
}
