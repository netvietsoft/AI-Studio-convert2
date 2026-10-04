// Function: sub_D9C52C
// RVA: 0xd9c52c, Size: 168 bytes
int64_t sub_D9C52C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D9AB3C(...); // call internal at 0xd9c55c
    sincosf(...); // call PLT API at 0xd9c584
    sub_D9C2AC(...); // call internal at 0xd9c5a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd9c5d0
}
