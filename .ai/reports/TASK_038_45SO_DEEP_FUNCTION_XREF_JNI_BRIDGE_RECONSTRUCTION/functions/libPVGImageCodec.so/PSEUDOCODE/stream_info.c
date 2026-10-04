// Function: stream_info
// RVA: 0x28144c, Size: 704 bytes
int64_t stream_info(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fputc(...); // call PLT API at 0x281490
    fflush(...); // call PLT API at 0x281498
    const char* str = "<stdin>";
    const char* str = "* %s %d image%s
";
    fprintf(...); // call PLT API at 0x2814d8
    const char* str = "  logical screen %dx%d
";
    fprintf(...); // call PLT API at 0x2814f0
    const char* str = "  global color table [%d]
";
    fprintf(...); // call PLT API at 0x28150c
    const char* str = "  |";
    sub_28170C(...); // call internal at 0x281524
    const char* str = "  background %d
";
    fprintf(...); // call PLT API at 0x281538
    const char* str = "  end comment ";
    fwrite(...); // call PLT API at 0x28156c
    sub_284D60(...); // call internal at 0x281580
    fputc(...); // call PLT API at 0x28158c
    const char* str = "  loop count %u
";
    fprintf(...); // call PLT API at 0x2815bc
    const char* str = "  loop forever
";
    fwrite(...); // call PLT API at 0x28161c
    const char* str = "  extensions %d
";
    fprintf(...); // call PLT API at 0x28167c
    sub_28192C(...); // call internal at 0x281694
    return a0;
    sub_28192C(...); // call internal at 0x2816f8
}
