// Function: sub_FABBAC
// RVA: 0xfabbac, Size: 984 bytes
int64_t sub_FABBAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xfabcb8
    sincosf(...); // call PLT API at 0xfabcd4
    sub_F91B04(...); // call internal at 0xfabd40
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfabf80
}
