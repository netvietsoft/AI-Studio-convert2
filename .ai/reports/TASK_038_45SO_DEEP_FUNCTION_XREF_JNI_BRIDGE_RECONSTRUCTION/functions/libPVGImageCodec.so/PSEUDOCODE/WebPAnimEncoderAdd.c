// Function: WebPAnimEncoderAdd
// RVA: 0x4921f8, Size: 1036 bytes
int64_t WebPAnimEncoderAdd(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_491740(...); // call internal at 0x49223c
    const char* str = "ERROR adding frame: timestamps must be non-decreasing";
    sub_492604(...); // call internal at 0x492298
    sub_49266C(...); // call internal at 0x4922b0
    sub_492A28(...); // call internal at 0x4922e4
    const char* str = "ERROR adding frame: Invalid frame dimensions";
    sub_492604(...); // call internal at 0x49238c
    const char* str = "WARNING: Converting frame from YUV(A) to ARGB format; this incurs a small loss.
";
    fprintf(...); // call PLT API at 0x4923d0
    WebPPictureYUVAToARGB(...); // call PLT API at 0x4923dc
    const char* str = "ERROR converting frame from YUV(A) to ARGB";
    sub_492604(...); // call internal at 0x4923f4
    WebPValidateConfig(...); // call PLT API at 0x492418
    const char* str = "ERROR adding frame: Invalid WebPConfig";
    sub_492604(...); // call internal at 0x492430
    sub_492D6C(...); // call internal at 0x492490
    const char* str = "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/mux/anim_encode.c";
    const char* str = "int WebPAnimEncoderAdd(WebPAnimEncoder *, WebPPicture *, int, const WebPConfig *)";
    const char* str = "enc->curr_canvas_ == NULL";
    __assert2(...); // call PLT API at 0x4924e8
    const char* str = "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/mux/anim_encode.c";
    const char* str = "int WebPAnimEncoderAdd(WebPAnimEncoder *, WebPPicture *, int, const WebPConfig *)";
    const char* str = "enc->curr_canvas_copy_modified_ == 1";
    __assert2(...); // call PLT API at 0x492544
    sub_492DA0(...); // call internal at 0x49254c
    sub_492E14(...); // call internal at 0x492558
    sub_492A28(...); // call internal at 0x492570
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x492600
}
