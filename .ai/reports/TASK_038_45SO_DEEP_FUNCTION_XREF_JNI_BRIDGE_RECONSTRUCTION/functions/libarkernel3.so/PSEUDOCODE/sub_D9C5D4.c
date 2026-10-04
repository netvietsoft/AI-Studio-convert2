// Function: sub_D9C5D4
// RVA: 0xd9c5d4, Size: 176 bytes
int64_t sub_D9C5D4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D9AB3C(...); // call internal at 0xd9c604
    sincosf(...); // call PLT API at 0xd9c62c
    sub_D9C2AC(...); // call internal at 0xd9c654
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd9c680
}
