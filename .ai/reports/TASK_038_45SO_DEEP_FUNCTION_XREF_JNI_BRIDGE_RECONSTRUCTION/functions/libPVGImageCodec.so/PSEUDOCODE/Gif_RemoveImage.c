// Function: Gif_RemoveImage
// RVA: 0x27f370, Size: 132 bytes
int64_t Gif_RemoveImage(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_DeleteImage(...); // call PLT API at 0x27f3a0
    return a0;
}
