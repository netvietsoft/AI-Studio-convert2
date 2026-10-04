// Function: sub_1A0FAC
// RVA: 0x1a0fac, Size: 2544 bytes
int64_t sub_1A0FAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_1A0FAC(...); // call internal at 0x1a1000
    sub_1A0FAC(...); // call internal at 0x1a17b8
    memmove(...); // call PLT API at 0x1a190c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1a1998
}
