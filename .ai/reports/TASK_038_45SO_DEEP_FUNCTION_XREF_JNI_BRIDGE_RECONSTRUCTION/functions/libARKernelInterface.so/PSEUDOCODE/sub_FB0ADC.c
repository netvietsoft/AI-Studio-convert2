// Function: sub_FB0ADC
// RVA: 0xfb0adc, Size: 476 bytes
int64_t sub_FB0ADC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xfb0b28
    free(...); // call PLT API at 0xfb0b4c
    _Znwm(...); // call PLT API at 0xfb0b60
    malloc(...); // call PLT API at 0xfb0b6c
    _Znwm(...); // call PLT API at 0xfb0b8c
    sub_FBD4F0(...); // call internal at 0xfb0bac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfb0cb4
}
