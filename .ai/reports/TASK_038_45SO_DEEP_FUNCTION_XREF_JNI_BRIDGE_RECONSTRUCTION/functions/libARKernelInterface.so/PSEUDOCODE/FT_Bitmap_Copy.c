// Function: FT_Bitmap_Copy
// RVA: 0xec0634, Size: 428 bytes
int64_t FT_Bitmap_Copy(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EBE448(...); // call internal at 0xec06e0
    sub_EBD698(...); // call internal at 0xec0718
    memcpy(...); // call PLT API at 0xec0754
    memcpy(...); // call PLT API at 0xec0794
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xec07dc
}
