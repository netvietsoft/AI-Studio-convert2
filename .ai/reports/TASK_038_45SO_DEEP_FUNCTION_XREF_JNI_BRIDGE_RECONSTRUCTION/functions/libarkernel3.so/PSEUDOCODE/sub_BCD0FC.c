// Function: sub_BCD0FC
// RVA: 0xbcd0fc, Size: 256 bytes
int64_t sub_BCD0FC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_BCD1FC(...); // call internal at 0xbcd158
    sub_BCD1FC(...); // call internal at 0xbcd1ac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xbcd1f8
}
