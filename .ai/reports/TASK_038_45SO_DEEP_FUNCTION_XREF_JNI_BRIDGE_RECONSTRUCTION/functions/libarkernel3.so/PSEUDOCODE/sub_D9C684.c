// Function: sub_D9C684
// RVA: 0xd9c684, Size: 168 bytes
int64_t sub_D9C684(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D9AB3C(...); // call internal at 0xd9c6b4
    sincosf(...); // call PLT API at 0xd9c6dc
    sub_D9C2AC(...); // call internal at 0xd9c6fc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd9c728
}
