// Function: sub_B7C00C
// RVA: 0xb7c00c, Size: 184 bytes
int64_t sub_B7C00C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B87880(...); // call internal at 0xb7c024
    sub_B78340(...); // call internal at 0xb7c03c
    return a0;
    realloc(...); // call PLT API at 0xb7c05c
    free(...); // call PLT API at 0xb7c068
    return a0;
    sub_B78AC8(...); // call internal at 0xb7c08c
    const char* str = "PANIC: unprotected error in call to Lua API (%s)
";
    fprintf(...); // call PLT API at 0xb7c0a8
    fflush(...); // call PLT API at 0xb7c0b0
    return a0;
}
