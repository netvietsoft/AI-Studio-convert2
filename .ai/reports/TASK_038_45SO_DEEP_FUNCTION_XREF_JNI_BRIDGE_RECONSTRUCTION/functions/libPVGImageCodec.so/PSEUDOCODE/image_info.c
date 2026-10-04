// Function: image_info
// RVA: 0x281e74, Size: 636 bytes
int64_t image_info(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_ImageNumber(...); // call PLT API at 0x281ea4
    fputc(...); // call PLT API at 0x281ec8
    fflush(...); // call PLT API at 0x281ed0
    const char* str = "  + image #%d ";
    fprintf(...); // call PLT API at 0x281ee8
    const char* str = "#%s ";
    fprintf(...); // call PLT API at 0x281f00
    const char* str = "%dx%d";
    fprintf(...); // call PLT API at 0x281f18
    const char* str = " at %d,%d";
    fprintf(...); // call PLT API at 0x281f38
    const char* str = " interlaced";
    fwrite(...); // call PLT API at 0x281f58
    const char* str = " transparent %d";
    fprintf(...); // call PLT API at 0x281f74
    fputc(...); // call PLT API at 0x281f80
    const char* str = "    compressed size %u
";
    fprintf(...); // call PLT API at 0x281fa0
    const char* str = "    comment ";
    fwrite(...); // call PLT API at 0x281fd4
    sub_284D60(...); // call internal at 0x281fe8
    fputc(...); // call PLT API at 0x281ff4
    const char* str = "    local color table [%d]
";
    fprintf(...); // call PLT API at 0x282020
    const char* str = "    |";
    sub_28170C(...); // call internal at 0x282038
    const char* str = "   ";
    fwrite(...); // call PLT API at 0x282060
    const char* str = " disposal %s";
    fprintf(...); // call PLT API at 0x282088
    const char* str = " delay %d.%02ds";
    fprintf(...); // call PLT API at 0x2820bc
    fputc(...); // call PLT API at 0x2820d8
    return a0;
}
