// Function: sub_297B40
// RVA: 0x297b40, Size: 856 bytes
int64_t sub_297B40(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "#stdout#";
    verbose_open(...); // call PLT API at 0x297b9c
    merge_frame_interval(...); // call PLT API at 0x297c14
    resize_stream(...); // call PLT API at 0x297c68
    kc_set_gamma(...); // call PLT API at 0x297c8c
    colormap_stream(...); // call PLT API at 0x297ca4
    kchist_make(...); // call PLT API at 0x297d04
    const char* str = "trivial adaptive palette (only %d colors in source)";
    warning(...); // call PLT API at 0x297d30
    (*x8)(...);
    colormap_stream(...); // call PLT API at 0x297d84
    Gif_DeleteColormap(...); // call PLT API at 0x297d8c
    kchist_cleanup(...); // call PLT API at 0x297d94
    apply_color_transforms(...); // call PLT API at 0x297da8
    optimize_fragments(...); // call PLT API at 0x297dc0
    const char* str = "wb";
    fopen(...); // call PLT API at 0x297dd4
    __errno(...); // call PLT API at 0x297de0
    strerror(...); // call PLT API at 0x297de8
    const char* str = "%s";
    lerror(...); // call PLT API at 0x297dfc
    Gif_FullWriteFile(...); // call PLT API at 0x297e20
    fclose(...); // call PLT API at 0x297e28
    Gif_DeleteStream(...); // call PLT API at 0x297e3c
    verbose_close(...); // call PLT API at 0x297e4c
    return a0;
    const char* str = "vendor/src/gifsicle.c";
    const char* str = "void merge_and_write_frames(const char *, int, int)";
    const char* str = "!nested_mode";
    __assert2(...); // call PLT API at 0x297e88
    const char* str = "can't happen";
    fatal_error(...); // call PLT API at 0x297e94
}
