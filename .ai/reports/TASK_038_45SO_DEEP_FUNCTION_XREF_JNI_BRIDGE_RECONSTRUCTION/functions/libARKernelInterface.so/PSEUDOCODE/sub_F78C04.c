// Function: sub_F78C04
// RVA: 0xf78c04, Size: 288 bytes
int64_t sub_F78C04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xf78c64
    free(...); // call PLT API at 0xf78c90
    _Znwm(...); // call PLT API at 0xf78ca4
    malloc(...); // call PLT API at 0xf78cb0
    _Znwm(...); // call PLT API at 0xf78cd0
    sub_F78D24(...); // call internal at 0xf78cf4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf78d20
}
