// Function: Gif_CopyStreamImages
// RVA: 0x27fd30, Size: 352 bytes
int64_t Gif_CopyStreamImages(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "vendor/src/giffunc.c";
    Gif_Realloc(...); // call PLT API at 0x27fd60
    Gif_CopyColormap(...); // call PLT API at 0x27fd9c
    Gif_DeleteStream(...); // call PLT API at 0x27fdcc
    const char* str = "vendor/src/giffunc.c";
    Gif_CopyImage(...); // call PLT API at 0x27fe2c
    Gif_Realloc(...); // call PLT API at 0x27fe68
    return a0;
}
