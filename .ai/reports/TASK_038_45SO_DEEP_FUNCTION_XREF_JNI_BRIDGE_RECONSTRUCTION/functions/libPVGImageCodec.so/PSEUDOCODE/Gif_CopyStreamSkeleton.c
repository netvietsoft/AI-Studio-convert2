// Function: Gif_CopyStreamSkeleton
// RVA: 0x27fa10, Size: 176 bytes
int64_t Gif_CopyStreamSkeleton(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "vendor/src/giffunc.c";
    Gif_Realloc(...); // call PLT API at 0x27fa38
    Gif_CopyColormap(...); // call PLT API at 0x27fa78
    Gif_DeleteStream(...); // call PLT API at 0x27faac
    return a0;
}
