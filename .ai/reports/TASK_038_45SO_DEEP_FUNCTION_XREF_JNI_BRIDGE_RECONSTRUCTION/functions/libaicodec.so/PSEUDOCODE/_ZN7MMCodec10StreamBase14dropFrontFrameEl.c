// Function: MMCodec::StreamBase::dropFrontFrame(long)
// RVA: 0x152ee4, Size: 1108 bytes
int64_t _ZN7MMCodec10StreamBase14dropFrontFrameEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x152f1c
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x152f3c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x152f5c
    _ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE4findIS1_EENS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEERKT_(...); // call imported API via PLT at 0x152f68
    _ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE4findIS1_EENS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEERKT_(...); // call imported API via PLT at 0x152f78
    _ZdlPv(...); // call imported API via PLT at 0x152f9c
    (*x8)(...); // indirect call at 0x152fb0
    pthread_self(...); // call imported API via PLT at 0x152fd8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6da3c = "[%s(%d)]:> [StreamBase(%p)](%ld):> add frame to hold pool failed"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x153004
    pthread_self(...); // call imported API via PLT at 0x153028
    const char* s_6da7d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> add frame to hold pool failed
"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x153050
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153058
    pthread_self(...); // call imported API via PLT at 0x153088
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8138e = "[%s(%d)]:> [StreamBase(%p)](%ld):> do nothing"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1530b4
    pthread_self(...); // call imported API via PLT at 0x1530d8
    const char* s_7e4f4 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> do nothing
"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x153100
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153120
    (*x8)(...); // indirect call at 0x153138
    pthread_self(...); // call imported API via PLT at 0x15316c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f689 = "[%s(%d)]:> [StreamBase(%p)](%ld):> add frame to cache pool failed"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x153198
    pthread_self(...); // call imported API via PLT at 0x1531bc
    const char* s_73338 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> add frame to cache pool failed
"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1531e4
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x1531f4
    pthread_self(...); // call imported API via PLT at 0x153228
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72013 = "[%s(%d)]:> [StreamBase(%p)](%ld):> media handle %p, drop last one video frame %lld, ref time %lld"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x153260
    pthread_self(...); // call imported API via PLT at 0x153284
    const char* s_7338c = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> media handle %p, drop last one video frame %lld, ref time %lld
"; // string xref
    const char* s_86792 = "dropFrontFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1532b8
    (*x8)(...); // indirect call at 0x1532d4
    _ZN7MMCodec10FrameQueue4nextEv(...); // call imported API via PLT at 0x1532dc
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x153318
    __stack_chk_fail(...); // call imported API via PLT at 0x153334
}
