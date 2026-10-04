// Function: sub_DA2DBC
// RVA: 0xda2dbc, Size: 164 bytes
int64_t sub_DA2DBC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsprintf_chk(...); // call PLT API at 0xda2e38
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xda2e5c
}
