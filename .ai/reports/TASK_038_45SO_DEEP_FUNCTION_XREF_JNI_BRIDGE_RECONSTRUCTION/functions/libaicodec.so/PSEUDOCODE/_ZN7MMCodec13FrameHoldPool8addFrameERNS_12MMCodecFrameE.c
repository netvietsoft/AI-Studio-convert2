// Function: MMCodec::FrameHoldPool::addFrame(MMCodec::MMCodecFrame&)
// RVA: 0x156490, Size: 1532 bytes
int64_t _ZN7MMCodec13FrameHoldPool8addFrameERNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x1564d8
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x1564e8
    _Znwm(...); // call imported API via PLT at 0x1564f8
    void* g_200678 = (void*)0x200678; // global ref
    (*x9)(...); // indirect call at 0x156530
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15653c
    _ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE25__emplace_unique_key_argsIS4_JRKS4_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x15654c
    (*x8)(...); // indirect call at 0x156568
    pthread_self(...); // call imported API via PLT at 0x156590
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84af0 = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1565c8
    pthread_self(...); // call imported API via PLT at 0x1565ec
    const char* s_8682e = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156620
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15662c
    pthread_self(...); // call imported API via PLT at 0x156660
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b52a = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d, un ref func %d"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1566b0
    pthread_self(...); // call imported API via PLT at 0x1566d4
    const char* s_89241 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d, un ref func %d
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156720
    return a0;
    pthread_self(...); // call imported API via PLT at 0x156770
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7340d = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> alloc MMCodecFrame failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15679c
    (*x8)(...); // indirect call at 0x1567c8
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x1567d4
    pthread_self(...); // call imported API via PLT at 0x156800
    const char* s_7f723 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> alloc MMCodecFrame failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156828
    sub_D867C(...); // call internal func at 0x156844
    pthread_self(...); // call imported API via PLT at 0x156868
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ed4e = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> mv ref frame %p failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x156898
    pthread_self(...); // call imported API via PLT at 0x1568bc
    const char* s_72075 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> mv ref frame %p failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1568e8
    pthread_self(...); // call imported API via PLT at 0x15691c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_690ac = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> Frame number:%zu"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15694c
    pthread_self(...); // call imported API via PLT at 0x156970
    const char* s_78414 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> Frame number:%zu
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15699c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1569a8
    (*x8)(...); // indirect call at 0x1569e0
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x1569e8
    sub_D867C(...); // call internal func at 0x156a04
    sub_D867C(...); // call internal func at 0x156a18
    __cxa_begin_catch(...); // call imported API via PLT at 0x156a20
    __cxa_rethrow(...); // call imported API via PLT at 0x156a40
    __cxa_end_catch(...); // call imported API via PLT at 0x156a48
    sub_CEBC4(...); // call internal func at 0x156a50
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x156a5c
    sub_155C50(...); // call internal func at 0x156a6c
    __stack_chk_fail(...); // call imported API via PLT at 0x156a88
}
