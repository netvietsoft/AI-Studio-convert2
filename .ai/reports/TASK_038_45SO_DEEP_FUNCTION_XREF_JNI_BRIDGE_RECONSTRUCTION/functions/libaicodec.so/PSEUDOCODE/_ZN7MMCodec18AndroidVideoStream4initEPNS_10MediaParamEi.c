// Function: MMCodec::AndroidVideoStream::init(MMCodec::MediaParam*, int)
// RVA: 0xf7268, Size: 836 bytes
int64_t _ZN7MMCodec18AndroidVideoStream4initEPNS_10MediaParamEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10MediaParam18readInVideoSettingEPNS_12VideoParam_tE(...); // call imported API via PLT at 0xf728c
    _ZN7MMCodec10MediaParam19readOutVideoSettingEPNS_12VideoParam_tE(...); // call imported API via PLT at 0xf729c
    pthread_self(...); // call imported API via PLT at 0xf7308
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f52b = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Read in video setting error!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7334
    pthread_self(...); // call imported API via PLT at 0xf7358
    const char* s_6bc30 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Read in video setting error!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf73a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81cd5 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> android video stream can't scale frame!!!!!!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf73cc
    pthread_self(...); // call imported API via PLT at 0xf73f0
    const char* s_8f988 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> android video stream can't scale frame!!!!!!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf7438
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f52b = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Read in video setting error!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7464
    pthread_self(...); // call imported API via PLT at 0xf7488
    const char* s_6bc30 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Read in video setting error!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf74b0
    return a0;
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf74c8
    av_image_get_buffer_size(...); // call imported API via PLT at 0xf74d4
    pthread_self(...); // call imported API via PLT at 0xf7504
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_74b32 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_image_get_buffer_size failed for format %d!!!!!!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7534
    pthread_self(...); // call imported API via PLT at 0xf7558
    const char* s_77bb7 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_image_get_buffer_size failed for format %d!!!!!!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7584
    _ZN7MMCodec14AndroidEncoder6createENS_18AndroidEncoderTypeE(...); // call imported API via PLT at 0xf7590
    return a0;
}
