// Function: Gif_ReleaseUncompressedImage
// RVA: 0x28033c, Size: 64 bytes
int64_t Gif_ReleaseUncompressedImage(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_Free(...); // call PLT API at 0x280350
    (*x8)(...);
    return a0;
}
