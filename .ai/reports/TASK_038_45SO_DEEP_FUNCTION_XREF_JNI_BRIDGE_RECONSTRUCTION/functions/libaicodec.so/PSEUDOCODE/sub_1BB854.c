// Function: sub_1BB854
// RVA: 0x1bb854, Size: 204 bytes
int64_t sub_1BB854(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb8d0
    memcpy(...); // call imported API via PLT at 0x1bb8f0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb91c
}
