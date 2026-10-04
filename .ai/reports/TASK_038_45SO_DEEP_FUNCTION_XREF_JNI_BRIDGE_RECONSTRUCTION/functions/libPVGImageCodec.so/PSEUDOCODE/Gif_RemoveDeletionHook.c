// Function: Gif_RemoveDeletionHook
// RVA: 0x2805f8, Size: 112 bytes
int64_t Gif_RemoveDeletionHook(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_Free(...); // call PLT API at 0x280660
    return a0;
}
