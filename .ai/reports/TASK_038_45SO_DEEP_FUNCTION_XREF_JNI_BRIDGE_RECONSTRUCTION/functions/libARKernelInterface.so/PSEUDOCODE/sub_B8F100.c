// Function: sub_B8F100
// RVA: 0xb8f100, Size: 284 bytes
int64_t sub_B8F100(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B7BFEC(...); // call internal at 0xb8f144
    free(...); // call PLT API at 0xb8f168
    _Znwm(...); // call PLT API at 0xb8f17c
    malloc(...); // call PLT API at 0xb8f188
    _Znwm(...); // call PLT API at 0xb8f1a8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb8f218
}
