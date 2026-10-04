// Function: sub_CD873C
// RVA: 0xcd873c, Size: 212 bytes
int64_t sub_CD873C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __emutls_get_address(...); // call PLT API at 0xcd87a0
    const char* str = "output buffer limit";
    realloc(...); // call PLT API at 0xcd87c0
    __emutls_get_address(...); // call PLT API at 0xcd87e8
    const char* str = "outofmem";
    return a0;
}
