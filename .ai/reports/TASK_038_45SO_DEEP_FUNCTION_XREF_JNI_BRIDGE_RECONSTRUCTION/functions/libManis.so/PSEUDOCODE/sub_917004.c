// Function: sub_917004
// RVA: 0x917004, Size: 180 bytes
int64_t sub_917004(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_92E3EC(...); // call internal at 0x91701c
    sub_910EC4(...); // call internal at 0x917030
    return a0;
    realloc(...); // call PLT API at 0x917050
    free(...); // call PLT API at 0x91705c
    return a0;
    sub_911DF8(...); // call internal at 0x917080
    const char* str = "PANIC: unprotected error in call to Lua API (%s)
";
    fprintf(...); // call PLT API at 0x91709c
    fflush(...); // call PLT API at 0x9170a4
    return a0;
}
