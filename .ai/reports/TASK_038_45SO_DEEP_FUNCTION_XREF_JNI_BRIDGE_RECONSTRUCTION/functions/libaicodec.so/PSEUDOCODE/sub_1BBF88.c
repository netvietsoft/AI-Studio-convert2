// Function: sub_1BBF88
// RVA: 0x1bbf88, Size: 204 bytes
int64_t sub_1BBF88(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc004
    memcpy(...); // call imported API via PLT at 0x1bc024
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc050
}
