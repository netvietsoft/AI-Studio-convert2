// Function: sub_ED1BF8
// RVA: 0xed1bf8, Size: 620 bytes
int64_t sub_ED1BF8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EB7040(...); // call internal at 0xed1c8c
    FT_MulFix(...); // call PLT API at 0xed1d34
    FT_DivFix(...); // call PLT API at 0xed1d98
    sub_EB7040(...); // call internal at 0xed1df4
    memcpy(...); // call PLT API at 0xed1e0c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xed1e60
}
