// Function: sub_FB84AC
// RVA: 0xfb84ac, Size: 356 bytes
int64_t sub_FB84AC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xfb8500
    free(...); // call PLT API at 0xfb851c
    _Znwm(...); // call PLT API at 0xfb8530
    malloc(...); // call PLT API at 0xfb853c
    _Znwm(...); // call PLT API at 0xfb855c
    sub_FB8610(...); // call internal at 0xfb857c
    sub_FB877C(...); // call internal at 0xfb85e0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb860c
}
