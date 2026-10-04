// Function: Gif_DeleteStream
// RVA: 0x27fb70, Size: 448 bytes
int64_t Gif_DeleteStream(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    Gif_DeleteImage(...); // call PLT API at 0x27fbc0
    Gif_Free(...); // call PLT API at 0x27fbd8
    Gif_Free(...); // call PLT API at 0x27fc04
    Gif_Free(...); // call PLT API at 0x27fc0c
    Gif_Free(...); // call PLT API at 0x27fc30
    Gif_Free(...); // call PLT API at 0x27fc48
    Gif_Free(...); // call PLT API at 0x27fc50
    (*x8)(...);
    Gif_Free(...); // call PLT API at 0x27fc84
    (*x8)(...);
    Gif_Free(...); // call PLT API at 0x27fca8
    Gif_Free(...); // call PLT API at 0x27fd08
    (*x8)(...);
}
