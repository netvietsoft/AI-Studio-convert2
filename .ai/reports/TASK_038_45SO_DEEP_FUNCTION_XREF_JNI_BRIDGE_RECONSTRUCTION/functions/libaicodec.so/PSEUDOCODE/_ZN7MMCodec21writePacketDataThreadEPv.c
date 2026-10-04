// Function: MMCodec::writePacketDataThread(void*)
// RVA: 0xdf5c8, Size: 3528 bytes
int64_t _ZN7MMCodec21writePacketDataThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0xdf638
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75d78 = "[%s(%d)]:> (%ld):> HLS Muxer does not exist, unable to create TS stream"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf660
    pthread_self(...); // call imported API via PLT at 0xdf684
    const char* s_71037 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> HLS Muxer does not exist, unable to create TS stream
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf6a8
    (*x8)(...); // indirect call at 0xdf6fc
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xdf724
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdf768
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdf774
    void* g_201390 = (void*)0x201390; // global ref
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE4takeERS4_i(...); // call imported API via PLT at 0xdf7b4
    pthread_self(...); // call imported API via PLT at 0xdf7ec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_710e8 = "[%s(%d)]:> (%ld):> packetQueue.take failed"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf814
    pthread_self(...); // call imported API via PLT at 0xdf838
    const char* s_89dd0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.take failed
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf85c
    _ZN7MMCodec17checkIsExitThreadERKNSt6__ndk16vectorIPNS_16ExportStreamBaseENS0_9allocatorIS3_EEEE(...); // call imported API via PLT at 0xdf870
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0xdf87c
    pthread_self(...); // call imported API via PLT at 0xdf8a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_710b6 = "[%s(%d)]:> (%ld):> !!! Encode thread all exit !!!"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf8cc
    const char* s_79fe8 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> !!! Encode thread all exit !!!
"; // string xref
    void* g_201028 = (void*)0x201028; // global ref
    void* g_201390 = (void*)0x201390; // global ref
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE4takeERS4_i(...); // call imported API via PLT at 0xdf924
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0xdf958
    (*x8)(...); // indirect call at 0xdf9ac
    (*x8)(...); // indirect call at 0xdf9c4
    _ZN7MMCodec8HLSMuxer9setPSDataEPhii(...); // call imported API via PLT at 0xdf9e4
    _ZN7MMCodec8HLSMuxer11writePacketEP8AVPacketb(...); // call imported API via PLT at 0xdf9f4
    pthread_self(...); // call imported API via PLT at 0xdfa1c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e325 = "[%s(%d)]:> (%ld):> fail to write packet to TS muxer"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdfa44
    pthread_self(...); // call imported API via PLT at 0xdfa68
    const char* s_8f72c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> fail to write packet to TS muxer
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdfa8c
    pthread_self(...); // call imported API via PLT at 0xdfab0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8196b = "[%s(%d)]:> (%ld):> Exit write thread !"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdfad8
    const char* s_7c6d7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Exit write thread !
"; // string xref
    void* g_201020 = (void*)0x201020; // global ref
    pthread_self(...); // call imported API via PLT at 0xdfb10
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdfb30
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdfb5c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdfb68
    pthread_self(...); // call imported API via PLT at 0xdfb9c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80744 = "[%s(%d)]:> (%ld):> get all packet!"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdfbc4
    pthread_self(...); // call imported API via PLT at 0xdfbe8
    const char* s_8c9ff = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> get all packet!
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdfc0c
    av_interleaved_write_frame(...); // call imported API via PLT at 0xdfc34
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdfc54
    strlen(...); // call imported API via PLT at 0xdfc5c
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0xdfc94
    memmove(...); // call imported API via PLT at 0xdfcb4
    const char* s_6ceb4 = "WriteFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdfccc
    _ZdlPv(...); // call imported API via PLT at 0xdfcf4
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdfd18
    pthread_self(...); // call imported API via PLT at 0xdfd3c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdfd68
    pthread_self(...); // call imported API via PLT at 0xdfd8c
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdfdb4
    (*x8)(...); // indirect call at 0xdfe04
    _ZdlPv(...); // call imported API via PLT at 0xdfe14
    (*x8)(...); // indirect call at 0xdfe40
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdfe48
    _ZN7MMCodec8HLSMuxer9setPSDataEPhii(...); // call imported API via PLT at 0xdfe6c
    pthread_self(...); // call imported API via PLT at 0xdfe94
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81992 = "[%s(%d)]:> (%ld):> none sps/pps data exit in software encoder."; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdfebc
    pthread_self(...); // call imported API via PLT at 0xdfee0
    const char* s_696d6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> none sps/pps data exit in software encoder.
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdff04
    pthread_self(...); // call imported API via PLT at 0xdff2c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_78c08 = "[%s(%d)]:> (%ld):> input parameter error!"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdff54
    pthread_self(...); // call imported API via PLT at 0xdff78
    const char* s_779a3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter error!
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdff9c
    pthread_self(...); // call imported API via PLT at 0xdffc4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71091 = "[%s(%d)]:> (%ld):> thread force quit"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdffec
    pthread_self(...); // call imported API via PLT at 0xe0010
    const char* s_8c9c8 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> thread force quit
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe0034
    _ZN7MMCodec17checkIsExitThreadERKNSt6__ndk16vectorIPNS_16ExportStreamBaseENS0_9allocatorIS3_EEEE(...); // call imported API via PLT at 0xe003c
    _ZN7MMCodec13ThreadContext5abortEv(...); // call imported API via PLT at 0xe0068
    _Znwm(...); // call imported API via PLT at 0xe0074
    const char* s_7b341 = "Write thread exit! when encode thread is running"; // string xref
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xe00a4
    pthread_self(...); // call imported API via PLT at 0xe00c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ad52 = "[%s(%d)]:> (%ld):> %s"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe00f4
    pthread_self(...); // call imported API via PLT at 0xe0118
    const char* s_82d9e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe0140
    _ZdlPv(...); // call imported API via PLT at 0xe0148
    (*x8)(...); // indirect call at 0xe01a0
    (*x8)(...); // indirect call at 0xe01f4
    pthread_self(...); // call imported API via PLT at 0xe0218
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ca34 = "[%s(%d)]:> (%ld):> muxer thread exit! index[0]:%d, index[1]:%d."; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe0244
    pthread_self(...); // call imported API via PLT at 0xe026c
    const char* s_75dc0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> muxer thread exit! index[0]:%d, index[1]:%d.
"; // string xref
    const char* s_83f26 = "writePacketDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe0294
    return a0;
    sub_D22F8(...); // call internal func at 0xe02e4
    sub_D867C(...); // call internal func at 0xe02fc
    _ZdlPv(...); // call imported API via PLT at 0xe0310
    _ZdlPv(...); // call imported API via PLT at 0xe032c
    _ZdlPv(...); // call imported API via PLT at 0xe034c
    sub_DC738(...); // call internal func at 0xe036c
    __stack_chk_fail(...); // call imported API via PLT at 0xe038c
}
