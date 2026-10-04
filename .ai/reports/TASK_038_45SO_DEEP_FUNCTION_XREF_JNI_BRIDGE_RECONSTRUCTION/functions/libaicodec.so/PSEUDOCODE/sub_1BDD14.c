// Function: sub_1BDD14
// RVA: 0x1bdd14, Size: 240 bytes
int64_t sub_1BDD14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bdd9c
    memcpy(...); // call imported API via PLT at 0x1bddc0
    memcpy(...); // call imported API via PLT at 0x1bddd0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bde00
}
