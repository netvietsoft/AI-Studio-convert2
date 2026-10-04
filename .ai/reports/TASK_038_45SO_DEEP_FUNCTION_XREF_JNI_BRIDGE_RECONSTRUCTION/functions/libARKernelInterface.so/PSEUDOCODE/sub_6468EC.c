// Function: sub_6468EC
// RVA: 0x6468ec, Size: 212 bytes
int64_t sub_6468EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __emutls_get_address(...); // call PLT API at 0x646950
    const char* str = "output buffer limit";
    realloc(...); // call PLT API at 0x646970
    __emutls_get_address(...); // call PLT API at 0x646998
    const char* str = "outofmem";
    return a0;
}
