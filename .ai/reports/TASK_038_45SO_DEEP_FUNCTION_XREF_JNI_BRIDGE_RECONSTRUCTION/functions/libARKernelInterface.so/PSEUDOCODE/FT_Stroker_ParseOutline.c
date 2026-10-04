// Function: FT_Stroker_ParseOutline
// RVA: 0xecaf40, Size: 856 bytes
int64_t FT_Stroker_ParseOutline(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    FT_Stroker_LineTo(...); // call PLT API at 0xecb0c4
    FT_Stroker_ConicTo(...); // call PLT API at 0xecb130
    FT_Stroker_CubicTo(...); // call PLT API at 0xecb1a0
    FT_Stroker_ConicTo(...); // call PLT API at 0xecb1c4
    FT_Stroker_ConicTo(...); // call PLT API at 0xecb1e8
    FT_Stroker_EndSubPath(...); // call PLT API at 0xecb1fc
    FT_Stroker_CubicTo(...); // call PLT API at 0xecb22c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xecb294
}
