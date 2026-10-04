// Function: MMCodec::FrameCachePool::addFrame(MMCodec::MMCodecFrame&)
// RVA: 0x15515c, Size: 2684 bytes
int64_t _ZN7MMCodec14FrameCachePool8addFrameERNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x1551e0
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x1551f0
    sub_155BD8(...); // call internal func at 0x155204
    (*x8)(...); // indirect call at 0x155220
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15522c
    _ZNSt6__ndk16__treeINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS2_11MMFrameCompENS_9allocatorIS4_EEE25__emplace_unique_key_argsIS4_JRKS4_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x15523c
    (*x8)(...); // indirect call at 0x155258
    pthread_self(...); // call imported API via PLT at 0x155280
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bf3a = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1552b8
    pthread_self(...); // call imported API via PLT at 0x1552dc
    const char* s_82854 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x155310
    pthread_self(...); // call imported API via PLT at 0x155338
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_798ee = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d, un ref func %d"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x155388
    pthread_self(...); // call imported API via PLT at 0x1553ac
    const char* s_79954 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d, un ref func %d
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1553f8
    return a0;
    pthread_self(...); // call imported API via PLT at 0x155450
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83988 = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> ignore %lld frame"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x155480
    pthread_self(...); // call imported API via PLT at 0x1554c4
    const char* s_7f6d8 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> ignore %lld frame
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1554f0
    (*x8)(...); // indirect call at 0x155508
    pthread_self(...); // call imported API via PLT at 0x155534
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ae72 = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> alloc MMCodecFrame failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x155560
    (*x8)(...); // indirect call at 0x15558c
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x155598
    pthread_self(...); // call imported API via PLT at 0x1555c4
    const char* s_839c1 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> alloc MMCodecFrame failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1555ec
    sub_D867C(...); // call internal func at 0x155608
    pthread_self(...); // call imported API via PLT at 0x15562c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_867f0 = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> mv ref frame %p failed"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15565c
    pthread_self(...); // call imported API via PLT at 0x155680
    const char* s_87a87 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> mv ref frame %p failed
"; // string xref
    const char* s_8f06d = "addFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1556ac
    const char* s_8f06d = "addFrame"; // string xref
    const char* s_82854 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0x1556f0
    (*x8)(...); // indirect call at 0x155788
    pthread_self(...); // call imported API via PLT at 0x1557a8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bf3a = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1557dc
    pthread_self(...); // call imported API via PLT at 0x1557f8
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x155824
    (*x8)(...); // indirect call at 0x1558a0
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x1558a8
    const char* s_8f06d = "addFrame"; // string xref
    void* g_201001 = (void*)0x201001; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x155930
    (*x8)(...); // indirect call at 0x1559e4
    pthread_self(...); // call imported API via PLT at 0x155a0c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bf3a = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x155a40
    pthread_self(...); // call imported API via PLT at 0x155a64
    const char* s_82854 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x155a94
    (*x8)(...); // indirect call at 0x155b10
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x155b18
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x155b24
    sub_155C50(...); // call internal func at 0x155b30
    sub_D867C(...); // call internal func at 0x155b4c
    sub_D867C(...); // call internal func at 0x155b60
    sub_D867C(...); // call internal func at 0x155b74
    sub_D867C(...); // call internal func at 0x155b88
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x155bb0
    sub_155C50(...); // call internal func at 0x155bb8
    __stack_chk_fail(...); // call imported API via PLT at 0x155bd4
}
