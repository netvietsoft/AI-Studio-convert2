// Function: Gif_WriterInit
// RVA: 0x2a1204, Size: 220 bytes
int64_t Gif_WriterInit(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_InitCompressInfo(...); // call PLT API at 0x2a1248
    const char* str = "vendor/src/gifwrite.c";
    Gif_Realloc(...); // call PLT API at 0x2a126c
    Gif_Realloc(...); // call PLT API at 0x2a1288
    return a0;
}
