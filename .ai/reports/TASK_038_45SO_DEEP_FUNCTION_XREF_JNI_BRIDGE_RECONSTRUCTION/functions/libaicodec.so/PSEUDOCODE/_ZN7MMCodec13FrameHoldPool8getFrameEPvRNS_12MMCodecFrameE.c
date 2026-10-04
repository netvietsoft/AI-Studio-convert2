// Function: MMCodec::FrameHoldPool::getFrame(void*, MMCodec::MMCodecFrame&)
// RVA: 0x156a8c, Size: 1140 bytes
int64_t _ZN7MMCodec13FrameHoldPool8getFrameEPvRNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x156ad4
    (*x8)(...); // indirect call at 0x156b18
    _ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE4findIS4_EENS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEERKT_(...); // call imported API via PLT at 0x156b3c
    pthread_self(...); // call imported API via PLT at 0x156b68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a302 = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x156ba8
    pthread_self(...); // call imported API via PLT at 0x156bcc
    const char* s_6dad0 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> input parameter is invalid, %p, mv ref func %d
"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156c08
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x156c2c
    return a0;
    pthread_self(...); // call imported API via PLT at 0x156c78
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ed4e = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> mv ref frame %p failed"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x156cac
    pthread_self(...); // call imported API via PLT at 0x156cc8
    const char* s_72075 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> mv ref frame %p failed
"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156cf8
    (*x8)(...); // indirect call at 0x156d10
    pthread_self(...); // call imported API via PLT at 0x156d30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84af0 = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x156d68
    pthread_self(...); // call imported API via PLT at 0x156d84
    const char* s_8682e = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156db8
    _ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE4findIS4_EENS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEERKT_(...); // call imported API via PLT at 0x156dc8
    (*x8)(...); // indirect call at 0x156e18
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x156e20
    _ZdlPv(...); // call imported API via PLT at 0x156e28
    pthread_self(...); // call imported API via PLT at 0x156e44
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_690ac = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> Frame number:%zu"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x156e74
    pthread_self(...); // call imported API via PLT at 0x156e90
    const char* s_78414 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> Frame number:%zu
"; // string xref
    const char* s_8a814 = "getFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x156ebc
    sub_D867C(...); // call internal func at 0x156ed4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x156ee0
    __stack_chk_fail(...); // call imported API via PLT at 0x156efc
}
