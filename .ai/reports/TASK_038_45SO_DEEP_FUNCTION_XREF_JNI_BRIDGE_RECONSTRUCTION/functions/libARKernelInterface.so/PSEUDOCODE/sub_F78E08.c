// Function: sub_F78E08
// RVA: 0xf78e08, Size: 468 bytes
int64_t sub_F78E08(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xf78e6c
    _Znwm(...); // call PLT API at 0xf78e84
    malloc(...); // call PLT API at 0xf78e90
    _Znwm(...); // call PLT API at 0xf78ed0
    sub_F78FDC(...); // call internal at 0xf78f98
    free(...); // call PLT API at 0xf78fa8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf78fd8
}
