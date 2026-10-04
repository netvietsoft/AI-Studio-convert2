// Function: FT_Get_Glyph
// RVA: 0xec01c4, Size: 336 bytes
int64_t FT_Get_Glyph(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_EBA8CC(...); // call internal at 0xec0250
    sub_EC00FC(...); // call internal at 0xec0268
    FT_Done_Glyph(...); // call PLT API at 0xec02ac
    return a0;
    (*x10)(...);
    __stack_chk_fail(...); // call PLT API at 0xec0310
}
