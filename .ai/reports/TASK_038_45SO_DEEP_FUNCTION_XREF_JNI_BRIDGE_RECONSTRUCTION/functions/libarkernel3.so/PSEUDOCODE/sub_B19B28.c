// Function: sub_B19B28
// RVA: 0xb19b28, Size: 164 bytes
int64_t sub_B19B28(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fstat(...); // call imported API via PLT at 0xb19b54
    mmap(...); // call imported API via PLT at 0xb19b8c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb19bc8
}
