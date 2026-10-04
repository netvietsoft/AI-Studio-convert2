// Function: MMCodec::FrameData::setOutVideoDataFormat(MMCodec::VideoParam_t const&)
// RVA: 0x126b7c, Size: 788 bytes
int64_t _ZN7MMCodec9FrameData21setOutVideoDataFormatERKNS_12VideoParam_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x126be4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d758 = "[%s(%d)]:> [FrameData(%p)](%ld):> input parameter invalid"; // string xref
    const char* s_88bf6 = "setOutVideoDataFormat"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x126c10
    pthread_self(...); // call imported API via PLT at 0x126c34
    const char* s_7a84d = "%s/MTMV_AICodec: [%s(%d)]:> [FrameData(%p)](%ld):> input parameter invalid
"; // string xref
    const char* s_88bf6 = "setOutVideoDataFormat"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x126c5c
    return a0;
    _Znwm(...); // call imported API via PLT at 0x126c7c
    const char* s_93895 = "superfast";
    const char* s_938d5 = "zerolatency";
    memcpy(...); // call imported API via PLT at 0x126d68
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x126d74
    av_image_get_buffer_size(...); // call imported API via PLT at 0x126d9c
    return a0;
    return a0;
    pthread_self(...); // call imported API via PLT at 0x126e00
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72db3 = "[%s(%d)]:> [FrameData(%p)](%ld):> av_image_get_buffer_size failed"; // string xref
    const char* s_88bf6 = "setOutVideoDataFormat"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x126e2c
    pthread_self(...); // call imported API via PLT at 0x126e50
    const char* s_83552 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameData(%p)](%ld):> av_image_get_buffer_size failed
"; // string xref
    const char* s_88bf6 = "setOutVideoDataFormat"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x126e78
    return a0;
}
