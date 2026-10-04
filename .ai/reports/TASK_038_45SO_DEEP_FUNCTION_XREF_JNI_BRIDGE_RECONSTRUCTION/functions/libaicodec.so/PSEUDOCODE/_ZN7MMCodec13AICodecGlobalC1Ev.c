// Function: MMCodec::AICodecGlobal::AICodecGlobal()
// RVA: 0x12e7c8, Size: 384 bytes
int64_t _ZN7MMCodec13AICodecGlobalC1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_log_set_callback(...); // call imported API via PLT at 0x12e7f4
    avformat_network_init(...); // call imported API via PLT at 0x12e7f8
    _ZN9JniHelper9getJavaVMEv(...); // call imported API via PLT at 0x12e7fc
    av_jni_set_java_vm(...); // call imported API via PLT at 0x12e804
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x12e834
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e934 = "[%s(%d)]:> Set vm error![%s]"; // string xref
    const char* s_6b008 = "AICodecGlobal"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12e85c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x12e884
    const char* s_67c04 = "%s/MTMV_AICodec: [%s(%d)]:> Set vm error![%s]
"; // string xref
    const char* s_6b008 = "AICodecGlobal"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12e8a8
    void* g_20ae80 = (void*)0x20ae80; // global ref
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0x12e8b8
    void* g_20a068 = (void*)0x20a068; // global ref
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0x12e8c4
    void* g_20aee8 = (void*)0x20aee8; // global ref
    _Znwm(...); // call imported API via PLT at 0x12e8d8
    _ZN7MMCodec10DeviceInfoC1Ev(...); // call imported API via PLT at 0x12e8e0
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x12e90c
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x12e914
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x12e928
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x12e93c
}
