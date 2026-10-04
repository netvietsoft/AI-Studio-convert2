// Function: Gif_Realloc
// RVA: 0x280c54, Size: 140 bytes
int64_t Gif_Realloc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call PLT API at 0x280c84
    return a0;
    free(...); // call PLT API at 0x280c94
    return a0;
    const char* str = "%s: Out of memory, giving up
";
    const char* str = "%s: Out of memory, giving up (huge allocation)
";
    fprintf(...); // call PLT API at 0x280cd4
    exit(...); // call PLT API at 0x280cdc
}
