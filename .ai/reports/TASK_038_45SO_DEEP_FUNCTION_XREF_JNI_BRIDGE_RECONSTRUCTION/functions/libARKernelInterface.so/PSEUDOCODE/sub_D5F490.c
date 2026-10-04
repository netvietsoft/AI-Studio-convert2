// Function: sub_D5F490
// RVA: 0xd5f490, Size: 168 bytes
int64_t sub_D5F490(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D5DAA0(...); // call internal at 0xd5f4c0
    sincosf(...); // call PLT API at 0xd5f4e8
    sub_D5F210(...); // call internal at 0xd5f508
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd5f534
}
