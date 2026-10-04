// Function: FT_Glyph_Stroke
// RVA: 0xecb298, Size: 296 bytes
int64_t FT_Glyph_Stroke(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    FT_Glyph_Copy(...); // call PLT API at 0xecb31c
    FT_Stroker_ParseOutline(...); // call PLT API at 0xecb338
    FT_Stroker_GetCounts(...); // call PLT API at 0xecb350
    FT_Outline_Done(...); // call PLT API at 0xecb35c
    FT_Outline_New(...); // call PLT API at 0xecb36c
    FT_Done_Glyph(...); // call PLT API at 0xecb37c
    FT_Stroker_Export(...); // call PLT API at 0xecb39c
    FT_Done_Glyph(...); // call PLT API at 0xecb3ac
    __stack_chk_fail(...); // call PLT API at 0xecb3bc
}
