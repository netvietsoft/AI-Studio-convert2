// Function: Gif_FullCompressImage
// RVA: 0x2a2824, Size: 1436 bytes
int64_t Gif_FullCompressImage(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_InitCompressInfo(...); // call PLT API at 0x2a2874
    const char* str = "vendor/src/gifwrite.c";
    Gif_Realloc(...); // call PLT API at 0x2a2898
    Gif_Realloc(...); // call PLT API at 0x2a28b4
    Gif_ReleaseCompressedImage(...); // call PLT API at 0x2a2990
    const char* str = "ut8";
    Gif_WriteCompressedData(...); // call PLT API at 0x2a2c60
    (*x8)(...);
    Gif_WriteCompressedData(...); // call PLT API at 0x2a2d10
    (*x8)(...);
    Gif_Free(...); // call PLT API at 0x2a2d88
    Gif_Free(...); // call PLT API at 0x2a2d90
    Gif_Free(...); // call PLT API at 0x2a2d98
    return a0;
}
