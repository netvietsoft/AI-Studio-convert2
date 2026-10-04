// Function: FT_Set_Default_Properties
// RVA: 0xec1374, Size: 472 bytes
int64_t FT_Set_Default_Properties(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "FREETYPE_PROPERTIES";
    getenv(...); // call PLT API at 0xec13ac
    sub_EBB330(...); // call internal at 0xec150c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xec1548
}
