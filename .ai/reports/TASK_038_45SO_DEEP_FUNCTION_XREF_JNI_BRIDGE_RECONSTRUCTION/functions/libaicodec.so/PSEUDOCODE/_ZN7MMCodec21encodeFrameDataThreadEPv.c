// Function: MMCodec::encodeFrameDataThread(void*)
// RVA: 0xdaabc, Size: 6152 bytes
int64_t _ZN7MMCodec21encodeFrameDataThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_get_media_type_string(...); // call imported API via PLT at 0xdab24
    pthread_self(...); // call imported API via PLT at 0xdab5c
    av_get_media_type_string(...); // call imported API via PLT at 0xdab74
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_683e5 = "[%s(%d)]:> (%ld):> [start>>>][%d:%s]ExportStreamBase %p"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdaba8
    (*x8)(...); // indirect call at 0xdac34
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xdac6c
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE4takeERS4_i(...); // call imported API via PLT at 0xdac84
    av_gettime_relative(...); // call imported API via PLT at 0xdac9c
    avcodec_send_frame(...); // call imported API via PLT at 0xdacb4
    av_gettime_relative(...); // call imported API via PLT at 0xdacbc
    (*x8)(...); // indirect call at 0xdacec
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xdacf0
    _Znwm(...); // call imported API via PLT at 0xdad04
    void* g_1fd870 = (void*)0x1fd870; // global ref
    avcodec_receive_packet(...); // call imported API via PLT at 0xdad28
    pthread_self(...); // call imported API via PLT at 0xdad58
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89d4b = "[%s(%d)]:> (%ld):> [%s]Buffer not enough, again"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdad80
    pthread_self(...); // call imported API via PLT at 0xdad9c
    const char* s_779df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%s]Buffer not enough, again
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdadc0
    pthread_self(...); // call imported API via PLT at 0xdadfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e25c = "[%s(%d)]:> (%ld):> frameQueue.take end, input end %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdae24
    pthread_self(...); // call imported API via PLT at 0xdae40
    const char* s_855f1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take end, input end %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdae64
    pthread_self(...); // call imported API via PLT at 0xdae80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_672e5 = "[%s(%d)]:> (%ld):> frameQueue.take end failed %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdaea8
    pthread_self(...); // call imported API via PLT at 0xdaec4
    const char* s_7c592 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take end failed %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdaee8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdaf10
    strlen(...); // call imported API via PLT at 0xdaf18
    pthread_self(...); // call imported API via PLT at 0xdaf64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdaf88
    pthread_self(...); // call imported API via PLT at 0xdafa4
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdafc4
    av_gettime_relative(...); // call imported API via PLT at 0xdafe4
    av_get_time_base_q(...); // call imported API via PLT at 0xdb008
    av_rescale_q(...); // call imported API via PLT at 0xdb018
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xdb028
    pthread_self(...); // call imported API via PLT at 0xdb054
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb080
    pthread_self(...); // call imported API via PLT at 0xdb09c
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb0c4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb0ec
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xdb0f8
    const char* s_8e24d = "Software receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdb10c
    _ZdlPv(...); // call imported API via PLT at 0xdb134
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdb158
    pthread_self(...); // call imported API via PLT at 0xdb17c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb1a4
    pthread_self(...); // call imported API via PLT at 0xdb1c0
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb1e4
    sub_D6E08(...); // call internal func at 0xdb214
    _ZdlPv(...); // call imported API via PLT at 0xdb224
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb24c
    pthread_self(...); // call imported API via PLT at 0xdb254
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e26c = "[%s(%d)]:> (%ld):> Encode data error![%s]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb27c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb29c
    pthread_self(...); // call imported API via PLT at 0xdb2a4
    const char* s_80708 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode data error![%s]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb2c8
    (*x8)(...); // indirect call at 0xdb2f4
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdb2fc
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0xdb310
    memmove(...); // call imported API via PLT at 0xdb330
    const char* s_8ace4 = "Software sendFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdb348
    _ZdlPv(...); // call imported API via PLT at 0xdb378
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdb39c
    pthread_self(...); // call imported API via PLT at 0xdb3c0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb3e8
    pthread_self(...); // call imported API via PLT at 0xdb404
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb428
    sub_D6E08(...); // call internal func at 0xdb458
    _ZdlPv(...); // call imported API via PLT at 0xdb468
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb490
    pthread_self(...); // call imported API via PLT at 0xdb498
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e214 = "[%s(%d)]:> (%ld):> Send data to codec context error![%s]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb4c0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb4e0
    pthread_self(...); // call imported API via PLT at 0xdb4e8
    const char* s_85638 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Send data to codec context error![%s]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb50c
    (*x8)(...); // indirect call at 0xdb538
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdb540
    pthread_self(...); // call imported API via PLT at 0xdb568
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_78c08 = "[%s(%d)]:> (%ld):> input parameter error!"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb590
    pthread_self(...); // call imported API via PLT at 0xdb5ac
    const char* s_779a3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter error!
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb5d0
    return a0;
    pthread_self(...); // call imported API via PLT at 0xdb628
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c82e = "[%s(%d)]:> (%ld):> input parameter invalid!"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb650
    pthread_self(...); // call imported API via PLT at 0xdb66c
    const char* s_8c85a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter invalid!
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb690
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0xdb698
    pthread_self(...); // call imported API via PLT at 0xdb6b8
    av_get_media_type_string(...); // call imported API via PLT at 0xdb6d0
    const char* s_855a7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [start>>>][%d:%s]ExportStreamBase %p
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb700
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdb71c
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdb72c
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdb734
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdb73c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdb744
    sub_D14D8(...); // call internal func at 0xdb76c
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xdb774
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdb77c
    pthread_self(...); // call imported API via PLT at 0xdb7a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b2c2 = "[%s(%d)]:> (%ld):> Encode thread force quit"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb7c8
    pthread_self(...); // call imported API via PLT at 0xdb7e4
    const char* s_83e4e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode thread force quit
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb808
    avcodec_send_frame(...); // call imported API via PLT at 0xdb814
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdb824
    strlen(...); // call imported API via PLT at 0xdb82c
    _Znwm(...); // call imported API via PLT at 0xdb86c
    memmove(...); // call imported API via PLT at 0xdb894
    const char* s_6b986 = "Software send null frame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdb8ac
    _ZdlPv(...); // call imported API via PLT at 0xdb8d4
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdb8fc
    pthread_self(...); // call imported API via PLT at 0xdb920
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c8c7 = "[%s(%d)]:> (%ld):> [flush %s]Send data to codec context error![%s]"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdb950
    pthread_self(...); // call imported API via PLT at 0xdb96c
    const char* s_89d7b = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [flush %s]Send data to codec context error![%s]
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdb998
    _ZdlPv(...); // call imported API via PLT at 0xdb9a8
    void* g_1fd8c0 = (void*)0x1fd8c0; // global ref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75d16 = "[%s(%d)]:> (%ld):> packetQueue.put %p"; // string xref
    (*x8)(...); // indirect call at 0xdb9fc
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xdba00
    _Znwm(...); // call imported API via PLT at 0xdba14
    avcodec_receive_packet(...); // call imported API via PLT at 0xdba30
    av_gettime_relative(...); // call imported API via PLT at 0xdba54
    pthread_self(...); // call imported API via PLT at 0xdba94
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbab8
    pthread_self(...); // call imported API via PLT at 0xdbadc
    const char* s_82d66 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put %p
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbb04
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xdbb10
    pthread_self(...); // call imported API via PLT at 0xdbb38
    const char* s_85683 = "[%s(%d)]:> (%ld):> packetQueue.put end %p %d"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbb64
    pthread_self(...); // call imported API via PLT at 0xdbb88
    const char* s_70f85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put end %p %d
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbbb4
    pthread_self(...); // call imported API via PLT at 0xdbbdc
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbc08
    pthread_self(...); // call imported API via PLT at 0xdbc2c
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbc58
    pthread_self(...); // call imported API via PLT at 0xdbc90
    const char* s_90ae4 = "[%s(%d)]:> (%ld):> Flush %s Encoder end"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbcb8
    pthread_self(...); // call imported API via PLT at 0xdbce4
    const char* s_7b2ee = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Flush %s Encoder end
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbd0c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdbd1c
    strlen(...); // call imported API via PLT at 0xdbd24
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0xdbd5c
    memmove(...); // call imported API via PLT at 0xdbd7c
    const char* s_82d41 = "Software flush receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdbd94
    _ZdlPv(...); // call imported API via PLT at 0xdbdc0
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdbde4
    pthread_self(...); // call imported API via PLT at 0xdbe08
    const char* s_83e8c = "[%s(%d)]:> (%ld):> Flush %s Encoder error[%s]"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbe34
    pthread_self(...); // call imported API via PLT at 0xdbe58
    const char* s_83eba = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Flush %s Encoder error[%s]
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbe84
    _ZdlPv(...); // call imported API via PLT at 0xdbe94
    (*x8)(...); // indirect call at 0xdbec0
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdbec8
    pthread_self(...); // call imported API via PLT at 0xdbef0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdbf18
    pthread_self(...); // call imported API via PLT at 0xdbf3c
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdbf60
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdbf68
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdbf78
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdbf80
    (*x8)(...); // indirect call at 0xdbff8
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0xdc000
    pthread_self(...); // call imported API via PLT at 0xdc030
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_749b9 = "[%s(%d)]:> (%ld):> [%d:%s]Encode thread exit! frameCnt %d"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdc068
    pthread_self(...); // call imported API via PLT at 0xdc084
    const char* s_8c90a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d:%s]Encode thread exit! frameCnt %d
"; // string xref
    const char* s_83e38 = "encodeFrameDataThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdc0b8
    sub_D22F8(...); // call internal func at 0xdc0d8
    sub_D22F8(...); // call internal func at 0xdc0f4
    sub_D22F8(...); // call internal func at 0xdc110
    _ZdlPv(...); // call imported API via PLT at 0xdc124
    _ZdlPv(...); // call imported API via PLT at 0xdc13c
    _ZdlPv(...); // call imported API via PLT at 0xdc158
    _ZdlPv(...); // call imported API via PLT at 0xdc170
    _ZdlPv(...); // call imported API via PLT at 0xdc18c
    _ZdlPv(...); // call imported API via PLT at 0xdc1ac
    _ZdlPv(...); // call imported API via PLT at 0xdc1c4
    __cxa_begin_catch(...); // call imported API via PLT at 0xdc1d0
    (*x8)(...); // indirect call at 0xdc1e0
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xdc1e8
    __cxa_rethrow(...); // call imported API via PLT at 0xdc200
    __cxa_end_catch(...); // call imported API via PLT at 0xdc208
    sub_CEBC4(...); // call internal func at 0xdc210
    _ZdlPv(...); // call imported API via PLT at 0xdc224
    sub_DC738(...); // call internal func at 0xdc234
    __cxa_begin_catch(...); // call imported API via PLT at 0xdc23c
    (*x8)(...); // indirect call at 0xdc24c
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xdc254
    __cxa_rethrow(...); // call imported API via PLT at 0xdc26c
    __cxa_end_catch(...); // call imported API via PLT at 0xdc274
    sub_CEBC4(...); // call internal func at 0xdc27c
    sub_D0AB4(...); // call internal func at 0xdc290
    sub_DC738(...); // call internal func at 0xdc2a0
    __stack_chk_fail(...); // call imported API via PLT at 0xdc2c0
}
