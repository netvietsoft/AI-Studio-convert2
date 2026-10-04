// Function: FT_Get_TrueType_Engine_Type
// RVA: 0xebb558, Size: 76 bytes
int64_t FT_Get_TrueType_Engine_Type(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "truetype";
    FT_Get_Module(...); // call PLT API at 0xebb56c
    const char* str = "truetype-engine";
    (*x8)(...);
    return a0;
}
