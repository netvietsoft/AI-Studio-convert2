// Function: sub_BA2378
// RVA: 0xba2378, Size: 2312 bytes
int64_t sub_BA2378(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    sub_BA01C8(...); // call internal func at 0xba2b20
    memcpy(...); // call imported API via PLT at 0xba2bc8
    sub_BA2C80(...); // call internal func at 0xba2bf8
    free(...); // call imported API via PLT at 0xba2c14
    return a0;
    free(...); // call imported API via PLT at 0xba2c60
    __stack_chk_fail(...); // call imported API via PLT at 0xba2c7c
}
