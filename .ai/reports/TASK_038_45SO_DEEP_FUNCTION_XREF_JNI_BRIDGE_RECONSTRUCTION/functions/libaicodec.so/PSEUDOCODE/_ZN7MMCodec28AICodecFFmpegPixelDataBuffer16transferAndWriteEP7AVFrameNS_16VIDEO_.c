// Function: MMCodec::AICodecFFmpegPixelDataBuffer::transferAndWrite(AVFrame*, MMCodec::VIDEO_PIX_FORMAT)
// RVA: 0x129700, Size: 3968 bytes
int64_t _ZN7MMCodec28AICodecFFmpegPixelDataBuffer16transferAndWriteEP7AVFrameNS_16VIDEO_PIX_FORMATE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_unref(...); // call imported API via PLT at 0x1298f4
    av_frame_alloc(...); // call imported API via PLT at 0x129904
    av_frame_ref(...); // call imported API via PLT at 0x129914
    _ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_(...); // call imported API via PLT at 0x12992c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_835a8 = "[%s(%d)]:> getPlaneWidthAndHeightWithFormat error!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1299cc
    const char* s_8ecbf = "%s/MTMV_AICodec: [%s(%d)]:> getPlaneWidthAndHeightWithFormat error!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x129a08
    return a0;
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x129a7c
    av_image_get_buffer_size(...); // call imported API via PLT at 0x129a90
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x129aa8
    av_image_fill_arrays(...); // call imported API via PLT at 0x129ad4
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0x129b04
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0x129b18
    _ZN7MMCodec15VideoFrameUtils13convertFormatEPKPKhPKimiiiiPPhPiRm(...); // call imported API via PLT at 0x129b48
    _ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_(...); // call imported API via PLT at 0x129b68
    void* g_201001 = (void*)0x201001; // global ref
    void* g_201001 = (void*)0x201001; // global ref
    void* g_201001 = (void*)0x201001; // global ref
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x129be4
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0x129bf0
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x129c00
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x129c34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87442 = "[%s(%d)]:> av_image_fill_arrays error![%s]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x129c5c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x129c88
    const char* s_8ed04 = "%s/MTMV_AICodec: [%s(%d)]:> av_image_fill_arrays error![%s]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x129cac
    av_image_get_buffer_size(...); // call imported API via PLT at 0x129cc4
    av_fast_realloc(...); // call imported API via PLT at 0x129ce0
    av_image_fill_arrays(...); // call imported API via PLT at 0x129d08
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0x129d28
    _ZN7MMCodec15VideoFrameUtils5scaleEPKPKhPKimiiiiiPPhPiRm(...); // call imported API via PLT at 0x129d5c
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0x129d84
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0x129d98
    _ZN7MMCodec15VideoFrameUtils13convertFormatEPKPKhPKimiiiiPPhPiRm(...); // call imported API via PLT at 0x129dc8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ce96 = "[%s(%d)]:> Video transfer error![%d]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x129e14
    const char* s_766e2 = "%s/MTMV_AICodec: [%s(%d)]:> Video transfer error![%d]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x129e54
    sws_scale(...); // call imported API via PLT at 0x129e80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7cebb = "[%s(%d)]:> Video sw transfer error![%d]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x129ed0
    const char* s_67bca = "%s/MTMV_AICodec: [%s(%d)]:> Video sw transfer error![%d]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x129f10
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_835a8 = "[%s(%d)]:> getPlaneWidthAndHeightWithFormat error!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x129f54
    const char* s_8ecbf = "%s/MTMV_AICodec: [%s(%d)]:> getPlaneWidthAndHeightWithFormat error!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x129f90
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72f40 = "[%s(%d)]:> av_image_get_buffer_size failed"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x129fd4
    const char* s_69e1c = "%s/MTMV_AICodec: [%s(%d)]:> av_image_get_buffer_size failed
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a010
    sws_scale(...); // call imported API via PLT at 0x12a03c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ce96 = "[%s(%d)]:> Video transfer error![%d]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a08c
    const char* s_766e2 = "%s/MTMV_AICodec: [%s(%d)]:> Video transfer error![%d]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a0cc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x12a0fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87442 = "[%s(%d)]:> av_image_fill_arrays error![%s]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a124
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x12a150
    const char* s_8ed04 = "%s/MTMV_AICodec: [%s(%d)]:> av_image_fill_arrays error![%s]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a174
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x12a188
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x12a198
    sws_getContext(...); // call imported API via PLT at 0x12a1cc
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x12a230
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x12a240
    sws_getContext(...); // call imported API via PLT at 0x12a274
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b7fb = "[%s(%d)]:> srcFormat(%d) or dstFormat(%d) is AV_PIX_FMT_NONE!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a30c
    const char* s_7bbd8 = "%s/MTMV_AICodec: [%s(%d)]:> srcFormat(%d) or dstFormat(%d) is AV_PIX_FMT_NONE!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b7fb = "[%s(%d)]:> srcFormat(%d) or dstFormat(%d) is AV_PIX_FMT_NONE!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a390
    const char* s_7bbd8 = "%s/MTMV_AICodec: [%s(%d)]:> srcFormat(%d) or dstFormat(%d) is AV_PIX_FMT_NONE!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a3d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d178 = "[%s(%d)]:> create sw scale failed!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a418
    const char* s_8b839 = "%s/MTMV_AICodec: [%s(%d)]:> create sw scale failed!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d178 = "[%s(%d)]:> create sw scale failed!"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a490
    const char* s_8b839 = "%s/MTMV_AICodec: [%s(%d)]:> create sw scale failed!
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a4cc
    sws_getCoefficients(...); // call imported API via PLT at 0x12a4e4
    sws_setColorspaceDetails(...); // call imported API via PLT at 0x12a510
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8068e = "[%s(%d)]:> sws_setColorspaceDetails error."; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a554
    const char* s_7d875 = "%s/MTMV_AICodec: [%s(%d)]:> sws_setColorspaceDetails error.
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a590
    sws_getCoefficients(...); // call imported API via PLT at 0x12a5a4
    sws_setColorspaceDetails(...); // call imported API via PLT at 0x12a5d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8068e = "[%s(%d)]:> sws_setColorspaceDetails error."; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12a614
    const char* s_7d875 = "%s/MTMV_AICodec: [%s(%d)]:> sws_setColorspaceDetails error.
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12a650
    _ZdlPv(...); // call imported API via PLT at 0x12a670
    __stack_chk_fail(...); // call imported API via PLT at 0x12a67c
}
