// Function: FT_Set_Char_Size
// RVA: 0xeb98f0, Size: 160 bytes
int64_t FT_Set_Char_Size(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    FT_Request_Size(...); // call PLT API at 0xeb9968
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xeb998c
}
