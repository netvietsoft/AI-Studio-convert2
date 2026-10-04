// Function: sub_FB5CB0
// RVA: 0xfb5cb0, Size: 316 bytes
int64_t sub_FB5CB0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xfb5d04
    malloc(...); // call PLT API at 0xfb5d48
    _Znwm(...); // call PLT API at 0xfb5d68
    sub_FB379C(...); // call internal at 0xfb5d9c
    free(...); // call PLT API at 0xfb5db0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb5de8
}
