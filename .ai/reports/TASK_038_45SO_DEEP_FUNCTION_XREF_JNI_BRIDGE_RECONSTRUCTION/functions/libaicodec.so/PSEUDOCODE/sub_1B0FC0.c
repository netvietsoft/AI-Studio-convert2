// Function: sub_1B0FC0
// RVA: 0x1b0fc0, Size: 300 bytes
int64_t sub_1B0FC0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_845ac = (void*)0x845ac; // global ref
    fopen(...); // call imported API via PLT at 0x1b0ff0
    fgets(...); // call imported API via PLT at 0x1b1008
    fgets(...); // call imported API via PLT at 0x1b1040
    strstr(...); // call imported API via PLT at 0x1b1060
    fclose(...); // call imported API via PLT at 0x1b106c
    const char* s_7481a = " msa"; // string xref
    strcmp(...); // call imported API via PLT at 0x1b107c
    fclose(...); // call imported API via PLT at 0x1b1094
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b10c4
    return a0;
    return a0;
}
