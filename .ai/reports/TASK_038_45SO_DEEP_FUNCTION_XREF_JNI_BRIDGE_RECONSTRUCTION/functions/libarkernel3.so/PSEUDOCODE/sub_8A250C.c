// Function: sub_8A250C
// RVA: 0x8a250c, Size: 96 bytes
int64_t sub_8A250C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_8A256C(...); // call internal at 0x8a2530
    _ZdlPv(...); // call PLT API at 0x8a2540
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x8a2568
}
