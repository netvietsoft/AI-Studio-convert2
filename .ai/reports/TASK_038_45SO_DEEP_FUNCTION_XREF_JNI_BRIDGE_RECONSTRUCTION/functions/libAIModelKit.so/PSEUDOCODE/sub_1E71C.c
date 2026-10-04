// Function: sub_1E71C
// RVA: 0x1e71c, Size: 164 bytes
int64_t sub_1E71C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call imported API via PLT at 0x1e798
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1e7bc
}
