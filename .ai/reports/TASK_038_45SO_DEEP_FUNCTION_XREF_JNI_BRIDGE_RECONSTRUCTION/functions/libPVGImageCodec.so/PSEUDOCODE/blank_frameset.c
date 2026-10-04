// Function: blank_frameset
// RVA: 0x284c48, Size: 232 bytes
int64_t blank_frameset(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_Free(...); // call PLT API at 0x284c88
    Gif_Free(...); // call PLT API at 0x284c9c
    Gif_DeleteStream(...); // call PLT API at 0x284ce8
    Gif_DeleteComment(...); // call PLT API at 0x284cf8
    blank_frameset(...); // call PLT API at 0x284d18
    return a0;
}
