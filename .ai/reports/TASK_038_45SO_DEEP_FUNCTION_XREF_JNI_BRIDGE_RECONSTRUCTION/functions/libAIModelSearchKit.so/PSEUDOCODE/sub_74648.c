// Function: sub_74648
// RVA: 0x74648, Size: 152 bytes
int64_t sub_74648(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call imported API via PLT at 0x746b8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x746dc
}
