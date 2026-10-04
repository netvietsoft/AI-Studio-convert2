// Function: FT_Attach_File
// RVA: 0xeb8b88, Size: 96 bytes
int64_t FT_Attach_File(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    FT_Attach_Stream(...); // call PLT API at 0xeb8bb8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xeb8be4
}
