// Function: FT_Glyph_To_Bitmap
// RVA: 0xec0410, Size: 508 bytes
int64_t FT_Glyph_To_Bitmap(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call PLT API at 0xec0494
    sub_EC00FC(...); // call internal at 0xec04c8
    (*x8)(...);
    (*x8)(...);
    sub_EBAA60(...); // call internal at 0xec0520
    (*x8)(...);
    sub_EBFDC4(...); // call internal at 0xec056c
    (*x8)(...);
    sub_EB6F98(...); // call internal at 0xec059c
    return a0;
    FT_Done_Glyph(...); // call PLT API at 0xec05f8
    __stack_chk_fail(...); // call PLT API at 0xec0608
}
