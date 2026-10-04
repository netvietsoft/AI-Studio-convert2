// Function: FT_Glyph_Copy
// RVA: 0xec0024, Size: 216 bytes
int64_t FT_Glyph_Copy(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EC00FC(...); // call internal at 0xec007c
    (*x8)(...);
    FT_Done_Glyph(...); // call PLT API at 0xec00bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xec00f8
}
