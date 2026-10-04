// Function: FT_Init_FreeType
// RVA: 0xec154c, Size: 132 bytes
int64_t FT_Init_FreeType(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_ECB984(...); // call internal at 0xec1560
    FT_New_Library(...); // call PLT API at 0xec1570
    sub_ECB9DC(...); // call internal at 0xec1580
    FT_Add_Module(...); // call PLT API at 0xec15a8
    FT_Set_Default_Properties(...); // call PLT API at 0xec15b8
    return a0;
}
