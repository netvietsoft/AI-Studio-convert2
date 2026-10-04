// Function: sub_1B0E94
// RVA: 0x1b0e94, Size: 300 bytes
int64_t sub_1B0E94(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_845ac = (void*)0x845ac; // global ref
    fopen(...); // call imported API via PLT at 0x1b0ec4
    fgets(...); // call imported API via PLT at 0x1b0edc
    const char* s_6f1d5 = " neon"; // string xref
    const char* s_7c3d8 = " asimd"; // string xref
    strstr(...); // call imported API via PLT at 0x1b0f14
    fgets(...); // call imported API via PLT at 0x1b0f28
    strstr(...); // call imported API via PLT at 0x1b0f44
    fclose(...); // call imported API via PLT at 0x1b0f6c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b0fb4
}
