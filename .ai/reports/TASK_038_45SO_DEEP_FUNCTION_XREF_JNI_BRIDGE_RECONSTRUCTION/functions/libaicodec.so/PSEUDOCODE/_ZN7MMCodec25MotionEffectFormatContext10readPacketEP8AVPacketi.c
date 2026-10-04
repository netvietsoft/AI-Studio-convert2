// Function: MMCodec::MotionEffectFormatContext::readPacket(AVPacket*, int)
// RVA: 0x14e108, Size: 3504 bytes
int64_t _ZN7MMCodec25MotionEffectFormatContext10readPacketEP8AVPacketi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_read_frame(...); // call imported API via PLT at 0x14e148
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14e168
    av_packet_unref(...); // call imported API via PLT at 0x14e17c
    av_read_frame(...); // call imported API via PLT at 0x14e18c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14e1b0
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14e1cc
    (*x8)(...); // indirect call at 0x14e1e0
    _ZN7MMCodec18MediaHandleContext17getKeyFrameTablesEi(...); // call imported API via PLT at 0x14e24c
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14e270
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14e2a8
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14e2f4
    pthread_self(...); // call imported API via PLT at 0x14e2fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ad70 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid packet:%lld, %lld, key frame:%lld + %lld"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e338
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14e370
    pthread_self(...); // call imported API via PLT at 0x14e378
    const char* s_6ec80 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid packet:%lld, %lld, key frame:%lld + %lld
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e3b0
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x14e3d0
    pthread_self(...); // call imported API via PLT at 0x14e3fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c47b = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of readPacket"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e428
    pthread_self(...); // call imported API via PLT at 0x14e44c
    const char* s_890bc = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of readPacket
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e474
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14e480
    return a0;
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x14e4d8
    av_packet_unref(...); // call imported API via PLT at 0x14e520
    av_get_media_type_string(...); // call imported API via PLT at 0x14e54c
    pthread_self(...); // call imported API via PLT at 0x14e554
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6fd78 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %s type stream isn't supported"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e584
    av_get_media_type_string(...); // call imported API via PLT at 0x14e5ac
    pthread_self(...); // call imported API via PLT at 0x14e5b4
    const char* s_7836e = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %s type stream isn't supported
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e5e0
    av_seek_frame(...); // call imported API via PLT at 0x14e610
    av_packet_unref(...); // call imported API via PLT at 0x14e620
    pthread_self(...); // call imported API via PLT at 0x14e648
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89112 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> getKeyFrameTables failed, %p"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e678
    pthread_self(...); // call imported API via PLT at 0x14e69c
    const char* s_755e9 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> getKeyFrameTables failed, %p
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e6c8
    pthread_self(...); // call imported API via PLT at 0x14e704
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_878f3 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> maybe can't get key frame %lld. end of %d:with:%lld, file:%lld->%lld, packet:%"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e770
    pthread_self(...); // call imported API via PLT at 0x14e798
    const char* s_8d9c2 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> maybe can't get key frame %lld. end of %d:with:%lld, file:%ll"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e800
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14e840
    void* g_2010f2 = (void*)0x2010f2; // global ref
    av_seek_frame(...); // call imported API via PLT at 0x14e858
    av_packet_unref(...); // call imported API via PLT at 0x14e868
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14e898
    pthread_self(...); // call imported API via PLT at 0x14e8a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d2f0 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e8d4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14e8fc
    pthread_self(...); // call imported API via PLT at 0x14e904
    const char* s_8d963 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14e934
    void* g_2010e4 = (void*)0x2010e4; // global ref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14e988
    pthread_self(...); // call imported API via PLT at 0x14e990
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d2f0 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14e9c4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14e9ec
    pthread_self(...); // call imported API via PLT at 0x14e9f4
    const char* s_8d963 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14ea24
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x14ea2c
    _ZN7MMCodec8protocol14parseFrameTypeEPhiiRiS2_(...); // call imported API via PLT at 0x14eaa8
    pthread_self(...); // call imported API via PLT at 0x14eb04
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b4a0 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of %d:with:%lld, file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14eb64
    pthread_self(...); // call imported API via PLT at 0x14eb9c
    const char* s_87865 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of %d:with:%lld, file:%lld->%lld, packet:%lld->%lld, fram"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14ebf8
    void* g_201001 = (void*)0x201001; // global ref
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14ec64
    void* g_2010f5 = (void*)0x2010f5; // global ref
    av_seek_frame(...); // call imported API via PLT at 0x14ec7c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14ecac
    pthread_self(...); // call imported API via PLT at 0x14ecb4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d2f0 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14ece8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14ed10
    pthread_self(...); // call imported API via PLT at 0x14ed18
    const char* s_8d963 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> av_seek_frame failed %d %s
"; // string xref
    const char* s_78363 = "readPacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14ed48
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x14ed50
    void* g_2010f1 = (void*)0x2010f1; // global ref
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x14ed94
    void* g_2010e3 = (void*)0x2010e3; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14edb4
    _ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIllEENS_22__unordered_map_hasherIlS2_NS_4hashIlEENS_8equal_toIlEELb1EEENS_21__unordered_map_equalIlS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIlJNS_4pairIllEEEEENSF_INS_15__hash_iteratorIPNS_11__hash_nodeIS2_PvEEEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x14edcc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14edd4
    void* g_2010e5 = (void*)0x2010e5; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14ee98
    __stack_chk_fail(...); // call imported API via PLT at 0x14eeb4
}
