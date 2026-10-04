// Function: sub_F7CB28
// RVA: 0xf7cb28, Size: 220 bytes
int64_t sub_F7CB28(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B9B524(...); // call internal at 0xf7cb80
    sub_F7CC04(...); // call internal at 0xf7cbb4
    free(...); // call PLT API at 0xf7cbc4
    free(...); // call PLT API at 0xf7cbd4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf7cc00
}
