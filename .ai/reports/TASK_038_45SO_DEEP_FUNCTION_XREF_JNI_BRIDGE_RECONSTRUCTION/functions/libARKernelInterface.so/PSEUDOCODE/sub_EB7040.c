// Function: sub_EB7040
// RVA: 0xeb7040, Size: 152 bytes
int64_t sub_EB7040(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EBE448(...); // call internal at 0xeb707c
    memset(...); // call PLT API at 0xeb70a0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xeb70d4
}
