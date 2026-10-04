// Function: Gif_CopyString
// RVA: 0x27f284, Size: 104 bytes
int64_t Gif_CopyString(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    strlen(...); // call PLT API at 0x27f29c
    const char* str = "vendor/src/giffunc.c";
    Gif_Realloc(...); // call PLT API at 0x27f2c0
    memcpy(...); // call PLT API at 0x27f2d4
    return a0;
}
