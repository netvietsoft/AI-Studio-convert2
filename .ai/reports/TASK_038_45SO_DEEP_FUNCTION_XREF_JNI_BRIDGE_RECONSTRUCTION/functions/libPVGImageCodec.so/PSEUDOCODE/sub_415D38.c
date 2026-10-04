// Function: sub_415D38
// RVA: 0x415d38, Size: 372 bytes
int64_t sub_415D38(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fstat(...); // call PLT API at 0x415d64
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x415db8
    sub_415D38(...); // call internal at 0x415dd8
    mmap(...); // call PLT API at 0x415e28
    return a0;
    munmap(...); // call PLT API at 0x415e9c
    return a0;
}
