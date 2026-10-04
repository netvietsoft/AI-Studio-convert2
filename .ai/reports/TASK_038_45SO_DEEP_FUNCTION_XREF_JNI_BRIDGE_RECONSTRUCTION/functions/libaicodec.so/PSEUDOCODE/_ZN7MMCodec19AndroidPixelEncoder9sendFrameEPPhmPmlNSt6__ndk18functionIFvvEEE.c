// Function: MMCodec::AndroidPixelEncoder::sendFrame(unsigned char**, unsigned long, unsigned long*, long, std::__ndk1::function<void ()>)
// RVA: 0xf6268, Size: 2776 bytes
int64_t _ZN7MMCodec19AndroidPixelEncoder9sendFrameEPPhmPmlNSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf62bc
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xf62d8
    (*x8)(...); // indirect call at 0xf62fc
    (*x8)(...); // indirect call at 0xf6318
    (*x8)(...); // indirect call at 0xf6330
    const char* s_81c11 = "sendFrame"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_712cc = "[%s(%d)]:> %s state is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6384
    const char* s_6bb24 = "%s/MTMV_AICodec: [%s(%d)]:> %s state is invalid
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf63c4
    return a0;
    const char* s_81c11 = "sendFrame"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6aa13 = "[%s(%d)]:> %s env is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf643c
    const char* s_6d029 = "%s/MTMV_AICodec: [%s(%d)]:> %s env is null
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_(...); // call imported API via PLT at 0xf64d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e581 = "[%s(%d)]:> cp frame data to input buffer failed"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6548
    const char* s_81c93 = "%s/MTMV_AICodec: [%s(%d)]:> cp frame data to input buffer failed
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    (*x8)(...); // indirect call at 0xf65a4
    (*x8)(...); // indirect call at 0xf65c8
    (*x8)(...); // indirect call at 0xf65e8
    (*x8)(...); // indirect call at 0xf6604
    (*x8)(...); // indirect call at 0xf6628
    (*x8)(...); // indirect call at 0xf6640
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xf6658
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f508 = "[%s(%d)]:> queueInputBuffer failed"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf66a4
    const char* s_6bbfb = "%s/MTMV_AICodec: [%s(%d)]:> queueInputBuffer failed
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf66e4
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xf66fc
    sub_F6D40(...); // call internal func at 0xf6714
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf6720
    (*x9)(...); // indirect call at 0xf6740
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf6760
    av_image_get_buffer_size(...); // call imported API via PLT at 0xf6770
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90c33 = "[%s(%d)]:> get image buffer size %d > capacity %d"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf67d0
    const char* s_7a375 = "%s/MTMV_AICodec: [%s(%d)]:> get image buffer size %d > capacity %d
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf6814
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf6848
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71394 = "[%s(%d)]:> get image buffer size %s"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6870
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf689c
    const char* s_7b622 = "%s/MTMV_AICodec: [%s(%d)]:> get image buffer size %s
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf68c0
    av_image_fill_arrays(...); // call imported API via PLT at 0xf68e8
    sub_1D8C58(...); // call internal func at 0xf6938
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68677 = "[%s(%d)]:> getPlaneWidthAndHeightWithFormat failed"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6984
    const char* s_686aa = "%s/MTMV_AICodec: [%s(%d)]:> getPlaneWidthAndHeightWithFormat failed
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf69c0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80892 = "[%s(%d)]:> image fill buffer failed %d"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6a10
    const char* s_6863e = "%s/MTMV_AICodec: [%s(%d)]:> image fill buffer failed %d
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    sub_1D8760(...); // call internal func at 0xf6aa4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89fb6 = "[%s(%d)]:> scale failed %d"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6af0
    const char* s_7ed8f = "%s/MTMV_AICodec: [%s(%d)]:> scale failed %d
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf6b30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90c65 = "[%s(%d)]:> video format scale %d unsupported"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf6b78
    const char* s_90c92 = "%s/MTMV_AICodec: [%s(%d)]:> video format scale %d unsupported
"; // string xref
    const char* s_81c11 = "sendFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf6bbc
    memcpy(...); // call imported API via PLT at 0xf6bcc
    memcpy(...); // call imported API via PLT at 0xf6c18
    void* g_2010f0 = (void*)0x2010f0; // global ref
    memcpy(...); // call imported API via PLT at 0xf6c64
    void* g_2010f1 = (void*)0x2010f1; // global ref
    (*x8)(...); // indirect call at 0xf6c90
    (*x8)(...); // indirect call at 0xf6cb4
    av_get_time_base_q(...); // call imported API via PLT at 0xf6cc0
    av_rescale_q(...); // call imported API via PLT at 0xf6cd4
    (*x8)(...); // indirect call at 0xf6cfc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf6d20
    __stack_chk_fail(...); // call imported API via PLT at 0xf6d3c
}
