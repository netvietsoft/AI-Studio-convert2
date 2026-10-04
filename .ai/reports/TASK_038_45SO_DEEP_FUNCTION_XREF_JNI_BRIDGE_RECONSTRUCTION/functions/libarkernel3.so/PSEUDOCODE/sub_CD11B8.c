// Function: sub_CD11B8
// RVA: 0xcd11b8, Size: 220 bytes
int64_t sub_CD11B8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    calloc(...); // call PLT API at 0xcd11d4
    sub_CDA488(...); // call internal at 0xcd121c
    __emutls_get_address(...); // call PLT API at 0xcd123c
    const char* str = "outofmem";
    __emutls_get_address(...); // call PLT API at 0xcd125c
    const char* str = "no SOI";
    free(...); // call PLT API at 0xcd127c
    return a0;
}
