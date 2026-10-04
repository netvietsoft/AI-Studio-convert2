// Function: sub_1B9CA8
// RVA: 0x1b9ca8, Size: 376 bytes
int64_t sub_1B9CA8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9d6c
    __memcpy_chk(...); // call imported API via PLT at 0x1b9d8c
    __memcpy_chk(...); // call imported API via PLT at 0x1b9da0
    memcpy(...); // call imported API via PLT at 0x1b9de4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b9e1c
}
