// Function: sub_650100
// RVA: 0x650100, Size: 248 bytes
int64_t sub_650100(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_6501F8(...); // call internal at 0x65015c
    memmove(...); // call PLT API at 0x650184
    memmove(...); // call PLT API at 0x6501bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x6501f4
}
