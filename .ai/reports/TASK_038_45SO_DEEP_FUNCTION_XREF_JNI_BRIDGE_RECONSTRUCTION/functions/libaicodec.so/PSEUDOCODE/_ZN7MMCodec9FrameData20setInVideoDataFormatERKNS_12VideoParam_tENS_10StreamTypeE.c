// Function: MMCodec::FrameData::setInVideoDataFormat(MMCodec::VideoParam_t const&, MMCodec::StreamType)
// RVA: 0x1268b8, Size: 708 bytes
int64_t _ZN7MMCodec9FrameData20setInVideoDataFormatERKNS_12VideoParam_tENS_10StreamTypeE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x1268f8
    const char* s_93895 = "superfast";
    const char* s_938d5 = "zerolatency";
    memcpy(...); // call imported API via PLT at 0x1269b0
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x1269c0
    av_image_get_buffer_size(...); // call imported API via PLT at 0x1269d8
    return a0;
    pthread_self(...); // call imported API via PLT at 0x126a20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d758 = "[%s(%d)]:> [FrameData(%p)](%ld):> input parameter invalid"; // string xref
    const char* s_7ce0c = "setInVideoDataFormat"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x126a4c
    pthread_self(...); // call imported API via PLT at 0x126a70
    const char* s_7a84d = "%s/MTMV_AICodec: [%s(%d)]:> [FrameData(%p)](%ld):> input parameter invalid
"; // string xref
    const char* s_7ce0c = "setInVideoDataFormat"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x126a98
    return a0;
    return a0;
    pthread_self(...); // call imported API via PLT at 0x126aec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72db3 = "[%s(%d)]:> [FrameData(%p)](%ld):> av_image_get_buffer_size failed"; // string xref
    const char* s_7ce0c = "setInVideoDataFormat"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x126b18
    pthread_self(...); // call imported API via PLT at 0x126b3c
    const char* s_83552 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameData(%p)](%ld):> av_image_get_buffer_size failed
"; // string xref
    const char* s_7ce0c = "setInVideoDataFormat"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x126b64
    return a0;
}
