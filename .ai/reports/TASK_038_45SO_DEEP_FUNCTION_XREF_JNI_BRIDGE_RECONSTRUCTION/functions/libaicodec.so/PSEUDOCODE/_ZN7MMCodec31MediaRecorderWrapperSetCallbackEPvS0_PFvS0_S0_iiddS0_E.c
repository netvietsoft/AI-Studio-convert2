// Function: MMCodec::MediaRecorderWrapperSetCallback(void*, void*, void (*)(void*, void*, int, int, double, double, void*))
// RVA: 0x194cb0, Size: 380 bytes
int64_t _ZN7MMCodec31MediaRecorderWrapperSetCallbackEPvS0_PFvS0_S0_iiddS0_E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2013b8 = (void*)0x2013b8; // global ref
    _ZN7MMCodec13MediaRecorder11setCallbackENSt6__ndk18functionIFvPS0_NS_14RecorderModuleENS_20RecorderCallbackTypeEddPvEEE(...); // call imported API via PLT at 0x194cec
    const char* s_70e59 = "MediaRecorderWrapperSetCallback"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x194d48
    const char* s_70e59 = "MediaRecorderWrapperSetCallback"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x194da4
    (*x8)(...); // indirect call at 0x194db8
    return a0;
    (*x9)(...); // indirect call at 0x194e0c
    __stack_chk_fail(...); // call imported API via PLT at 0x194e28
}
