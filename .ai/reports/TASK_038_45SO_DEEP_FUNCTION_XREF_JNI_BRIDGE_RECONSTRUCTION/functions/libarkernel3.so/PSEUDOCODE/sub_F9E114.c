// Function: sub_F9E114
// RVA: 0xf9e114, Size: 316 bytes
int64_t sub_F9E114(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_F9E250(...); // call internal at 0xf9e170
    memmove(...); // call PLT API at 0xf9e1a8
    memmove(...); // call PLT API at 0xf9e204
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf9e24c
}
