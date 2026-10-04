// Function: sub_FB70C0
// RVA: 0xfb70c0, Size: 324 bytes
int64_t sub_FB70C0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xfb711c
    malloc(...); // call PLT API at 0xfb7160
    _Znwm(...); // call PLT API at 0xfb7180
    sub_FB7204(...); // call internal at 0xfb71b4
    free(...); // call PLT API at 0xfb71cc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb7200
}
