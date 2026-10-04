// Function: sub_D5F5E8
// RVA: 0xd5f5e8, Size: 168 bytes
int64_t sub_D5F5E8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D5DAA0(...); // call internal at 0xd5f618
    sincosf(...); // call PLT API at 0xd5f640
    sub_D5F210(...); // call internal at 0xd5f660
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd5f68c
}
