// Function: MMCodec::StreamBase::releaseVideoFrameBuffer(void*)
// RVA: 0x153514, Size: 672 bytes
int64_t _ZN7MMCodec10StreamBase23releaseVideoFrameBufferEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x153550
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15355c
    _ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE4findIS1_EENS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEERKT_(...); // call imported API via PLT at 0x153568
    _ZdlPv(...); // call imported API via PLT at 0x15358c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153594
    pthread_self(...); // call imported API via PLT at 0x1535c0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8138e = "[%s(%d)]:> [StreamBase(%p)](%ld):> do nothing"; // string xref
    const char* s_6fe79 = "releaseVideoFrameBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1535ec
    pthread_self(...); // call imported API via PLT at 0x153610
    const char* s_7e4f4 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> do nothing
"; // string xref
    const char* s_6fe79 = "releaseVideoFrameBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x153638
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153648
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x153650
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x153660
    (*x8)(...); // indirect call at 0x15367c
    (*x8)(...); // indirect call at 0x153698
    _ZN7MMCodec12MMCodecFrame5resetEv(...); // call imported API via PLT at 0x1536a0
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x1536ac
    pthread_self(...); // call imported API via PLT at 0x1536d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87a4a = "[%s(%d)]:> [StreamBase(%p)](%ld):> alloc MMCodecFrame failed"; // string xref
    const char* s_6fe79 = "releaseVideoFrameBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x153704
    pthread_self(...); // call imported API via PLT at 0x153728
    const char* s_867a1 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> alloc MMCodecFrame failed
"; // string xref
    const char* s_6fe79 = "releaseVideoFrameBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x153750
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x15375c
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153794
    __stack_chk_fail(...); // call imported API via PLT at 0x1537b0
}
