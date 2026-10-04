// Function: MMCodec::MTMediaReader::setAICodecContext(MMCodec::AICodecContext*)
// RVA: 0x130184, Size: 288 bytes
int64_t _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1301a0
    pthread_self(...); // call imported API via PLT at 0x1301cc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ed8b = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> started"; // string xref
    const char* s_874ba = "setAICodecContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1301f8
    pthread_self(...); // call imported API via PLT at 0x13021c
    const char* s_7ceea = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> started
"; // string xref
    const char* s_874ba = "setAICodecContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x130244
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x130254
    _ZN7MMCodec6AVIRef6retainEv(...); // call imported API via PLT at 0x130264
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x130278
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x130298
}
