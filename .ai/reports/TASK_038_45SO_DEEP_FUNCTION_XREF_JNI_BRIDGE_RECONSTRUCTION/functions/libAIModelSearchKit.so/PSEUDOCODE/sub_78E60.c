// Function: sub_78E60
// RVA: 0x78e60, Size: 152 bytes
int64_t sub_78E60(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call imported API via PLT at 0x78ed0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x78ef4
}
