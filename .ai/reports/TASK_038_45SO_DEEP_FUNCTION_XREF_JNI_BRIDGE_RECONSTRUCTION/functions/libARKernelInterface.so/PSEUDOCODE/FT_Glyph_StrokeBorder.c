// Function: FT_Glyph_StrokeBorder
// RVA: 0xecb3c0, Size: 340 bytes
int64_t FT_Glyph_StrokeBorder(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    FT_Glyph_Copy(...); // call PLT API at 0xecb450
    FT_Outline_Get_Orientation(...); // call PLT API at 0xecb464
    FT_Stroker_ParseOutline(...); // call PLT API at 0xecb484
    FT_Stroker_GetBorderCounts(...); // call PLT API at 0xecb4a0
    FT_Outline_Done(...); // call PLT API at 0xecb4ac
    FT_Outline_New(...); // call PLT API at 0xecb4bc
    FT_Done_Glyph(...); // call PLT API at 0xecb4cc
    FT_Stroker_ExportBorder(...); // call PLT API at 0xecb4f0
    FT_Done_Glyph(...); // call PLT API at 0xecb500
    __stack_chk_fail(...); // call PLT API at 0xecb510
}
