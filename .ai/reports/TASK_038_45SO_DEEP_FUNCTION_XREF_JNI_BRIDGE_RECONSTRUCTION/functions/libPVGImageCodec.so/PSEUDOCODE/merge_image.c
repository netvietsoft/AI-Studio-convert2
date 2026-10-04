// Function: merge_image
// RVA: 0x28cb58, Size: 1520 bytes
int64_t merge_image(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_ImageColorBound(...); // call PLT API at 0x28cba8
    const char* str = "some colors undefined by colormap";
    lwarning(...); // call PLT API at 0x28cc84
    merge_colormap_if_possible(...); // call PLT API at 0x28ccd4
    Gif_NewFullColormap(...); // call PLT API at 0x28cd2c
    Gif_NewImage(...); // call PLT API at 0x28ceac
    Gif_CopyString(...); // call PLT API at 0x28cebc
    Gif_CreateUncompressedImage(...); // call PLT API at 0x28cf24
    Gif_CreateUncompressedImage(...); // call PLT API at 0x28cf30
    memcpy(...); // call PLT API at 0x28cf5c
    const char* str = "vendor/src/merge.c";
    Gif_Realloc(...); // call PLT API at 0x28d000
    memcpy(...); // call PLT API at 0x28d01c
    Gif_NewComment(...); // call PLT API at 0x28d028
    Gif_AddComment(...); // call PLT API at 0x28d058
    Gif_AddExtension(...); // call PLT API at 0x28d090
    Gif_AddImage(...); // call PLT API at 0x28d0a8
    return a0;
    Gif_CopyExtension(...); // call PLT API at 0x28d0d4
    Gif_AddExtension(...); // call PLT API at 0x28d0e4
    const char* str = "vendor/src/merge.c";
    const char* str = "Gif_Image *merge_image(Gif_Stream *, Gif_Stream *, Gif_Image *, Gt_Frame *, int)";
    const char* str = "destcm->ncol <= 256";
    __assert2(...); // call PLT API at 0x28d124
    const char* str = "vendor/src/merge.c";
    const char* str = "Gif_Image *merge_image(Gif_Stream *, Gif_Stream *, Gif_Image *, Gt_Frame *, int)";
    const char* str = "c->haspixel == 2 && found_transparent < 256";
    __assert2(...); // call PLT API at 0x28d144
}
