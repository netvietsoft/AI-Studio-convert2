// Function: MMCodec::MotionEffectFormatContext::receiveFrame(MMCodec::DecoderBase*, int, MMCodec::MMCodecFrame*)
// RVA: 0x14f330, Size: 5860 bytes
int64_t _ZN7MMCodec25MotionEffectFormatContext12receiveFrameEPNS_11DecoderBaseEiPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x14f3a4
    pthread_self(...); // call imported API via PLT at 0x14f3f0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71eea = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> stream index is invalid %d"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14f420
    pthread_self(...); // call imported API via PLT at 0x14f444
    const char* s_68f93 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> stream index is invalid %d
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14f470
    return a0;
    pthread_self(...); // call imported API via PLT at 0x14f4cc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90614 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> avstream is null"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14f4f8
    pthread_self(...); // call imported API via PLT at 0x14f51c
    const char* s_76ad6 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> avstream is null
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14f544
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14f584
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x14f598
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x14f5a0
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x14f5a8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14f5b8
    _ZN7MMCodec13FormatContext12receiveFrameEPNS_11DecoderBaseEiPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x14f5d8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14f5e4
    (*x8)(...); // indirect call at 0x14f5f8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x14f648
    av_get_time_base_q(...); // call imported API via PLT at 0x14f6e0
    av_rescale_q(...); // call imported API via PLT at 0x14f6f0
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x14f718
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x14f728
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x14f7e8
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x14f7f8
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x14f7fc
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x14f808
    pthread_self(...); // call imported API via PLT at 0x14f830
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8798f = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14f89c
    pthread_self(...); // call imported API via PLT at 0x14f8c0
    const char* s_71f37 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, fr"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14f928
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x14f934
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x14f944
    av_get_time_base_q(...); // call imported API via PLT at 0x14fa94
    av_rescale_q(...); // call imported API via PLT at 0x14faa4
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x14fad4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x14fae4
    av_get_time_base_q(...); // call imported API via PLT at 0x14fb94
    av_rescale_q(...); // call imported API via PLT at 0x14fba4
    av_get_time_base_q(...); // call imported API via PLT at 0x14fbbc
    av_rescale_q(...); // call imported API via PLT at 0x14fbcc
    _ZdlPv(...); // call imported API via PLT at 0x14fbf8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14fc00
    pthread_self(...); // call imported API via PLT at 0x14fc88
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c4bf = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> maybe got before segment frame %lld:> %lld, current key frame:%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14fcbc
    pthread_self(...); // call imported API via PLT at 0x14fce0
    const char* s_7add7 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> maybe got before segment frame %lld:> %lld, current key frame"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14fd1c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x14fd30
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x14fd34
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x14fd40
    pthread_self(...); // call imported API via PLT at 0x14fd68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8798f = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14fdd4
    pthread_self(...); // call imported API via PLT at 0x14fdf8
    const char* s_71f37 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, fr"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14fe60
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x14fe6c
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x14fe7c
    pthread_self(...); // call imported API via PLT at 0x14fed0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d387 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> receive_again"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14fefc
    pthread_self(...); // call imported API via PLT at 0x14ff20
    const char* s_8bd56 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> receive_again
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14ff48
    (*x8)(...); // indirect call at 0x14ff78
    av_get_time_base_q(...); // call imported API via PLT at 0x14ffd0
    av_rescale_q(...); // call imported API via PLT at 0x14ffe0
    av_get_time_base_q(...); // call imported API via PLT at 0x14fff4
    av_rescale_q(...); // call imported API via PLT at 0x150004
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x150010
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x150018
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x150024
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x150034
    sub_150C14(...); // call internal func at 0x150040
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x150058
    pthread_self(...); // call imported API via PLT at 0x15008c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e494 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid frame:%lld:> %lld, key frame:%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1500c0
    pthread_self(...); // call imported API via PLT at 0x1500e4
    const char* s_90657 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid frame:%lld:> %lld, key frame:%lld
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150120
    (*x8)(...); // indirect call at 0x150138
    pthread_self(...); // call imported API via PLT at 0x150170
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8798f = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1501cc
    pthread_self(...); // call imported API via PLT at 0x1501f0
    const char* s_71f37 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, fr"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15025c
    (*x8)(...); // indirect call at 0x150270
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x150280
    (*x8)(...); // indirect call at 0x1502b0
    pthread_self(...); // call imported API via PLT at 0x1502d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82788 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d acquireFrame failed"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150308
    pthread_self(...); // call imported API via PLT at 0x15032c
    const char* s_76b2b = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d acquireFrame failed
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150358
    (*x8)(...); // indirect call at 0x15036c
    pthread_self(...); // call imported API via PLT at 0x1503b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8798f = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150410
    pthread_self(...); // call imported API via PLT at 0x15044c
    const char* s_71f37 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, fr"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1504b0
    void* g_2010f4 = (void*)0x2010f4; // global ref
    av_get_time_base_q(...); // call imported API via PLT at 0x150530
    av_rescale_q(...); // call imported API via PLT at 0x150540
    av_get_time_base_q(...); // call imported API via PLT at 0x150558
    pthread_self(...); // call imported API via PLT at 0x150580
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d33d = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> _dumpCacheFrame got bug"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1505ac
    pthread_self(...); // call imported API via PLT at 0x1505d0
    const char* s_6a2a6 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> _dumpCacheFrame got bug
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1505f8
    pthread_self(...); // call imported API via PLT at 0x150620
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68ff2 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of receiveFrame"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15064c
    pthread_self(...); // call imported API via PLT at 0x150670
    const char* s_7564a = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> end of receiveFrame
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150698
    (*x8)(...); // indirect call at 0x1506b0
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(...); // call imported API via PLT at 0x1506d0
    pthread_self(...); // call imported API via PLT at 0x15070c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bda8 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> allocAVFrame failed"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150738
    pthread_self(...); // call imported API via PLT at 0x15075c
    const char* s_8bdee = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> allocAVFrame failed
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150784
    pthread_self(...); // call imported API via PLT at 0x1507b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82788 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d acquireFrame failed"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1507e0
    pthread_self(...); // call imported API via PLT at 0x150824
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82788 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d acquireFrame failed"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150854
    pthread_self(...); // call imported API via PLT at 0x15087c
    const char* s_76b2b = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d acquireFrame failed
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1508a8
    (*x8)(...); // indirect call at 0x1508bc
    pthread_self(...); // call imported API via PLT at 0x1508f0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f630 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid frame:%lld, key frame:%lld"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150924
    pthread_self(...); // call imported API via PLT at 0x15094c
    const char* s_6fdc9 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> get invalid frame:%lld, key frame:%lld
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150980
    (*x8)(...); // indirect call at 0x150998
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1509a4
    __stack_chk_fail(...); // call imported API via PLT at 0x1509bc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1509f4
}
