// Function: sub_1BD588
// RVA: 0x1bd588, Size: 200 bytes
int64_t sub_1BD588(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd5f4
    memcpy(...); // call imported API via PLT at 0x1bd620
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd64c
}
