// Function: MMCodec::androidEncodePixelThread(void*)
// RVA: 0xddc6c, Size: 6492 bytes
int64_t _ZN7MMCodec24androidEncodePixelThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0xddcf4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c988 = "[%s(%d)]:> (%ld):> [start>>>][%d]AndroidVideoPixelStreamBase %p"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xddd28
    (*x8)(...); // indirect call at 0xddda0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    const char* s_70fff = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take %p
"; // string xref
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xddddc
    pthread_self(...); // call imported API via PLT at 0xdde08
    const char* s_7d910 = "[%s(%d)]:> (%ld):> frameQueue.take %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdde2c
    pthread_self(...); // call imported API via PLT at 0xdde50
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdde70
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE4takeERS4_i(...); // call imported API via PLT at 0xdde80
    pthread_self(...); // call imported API via PLT at 0xddeb8
    const char* s_8f6b7 = "[%s(%d)]:> (%ld):> frameQueue.take end %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xddedc
    pthread_self(...); // call imported API via PLT at 0xddf00
    const char* s_7c644 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take end %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xddf24
    av_gettime_relative(...); // call imported API via PLT at 0xddf28
    (*x8)(...); // indirect call at 0xddf70
    pthread_self(...); // call imported API via PLT at 0xddfbc
    const char* s_6e25c = "[%s(%d)]:> (%ld):> frameQueue.take end, input end %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xddfe0
    pthread_self(...); // call imported API via PLT at 0xde004
    const char* s_855f1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take end, input end %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde028
    pthread_self(...); // call imported API via PLT at 0xde044
    const char* s_672e5 = "[%s(%d)]:> (%ld):> frameQueue.take end failed %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde068
    pthread_self(...); // call imported API via PLT at 0xde08c
    const char* s_7c592 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> frameQueue.take end failed %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde0b0
    (*x8)(...); // indirect call at 0xde0cc
    av_gettime_relative(...); // call imported API via PLT at 0xde0d0
    (*x8)(...); // indirect call at 0xde100
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xde104
    _Znwm(...); // call imported API via PLT at 0xde118
    void* g_1fd9b0 = (void*)0x1fd9b0; // global ref
    (*x8)(...); // indirect call at 0xde144
    pthread_self(...); // call imported API via PLT at 0xde174
    const char* s_8c956 = "[%s(%d)]:> (%ld):> video Buffer not enough, again"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde194
    pthread_self(...); // call imported API via PLT at 0xde1b8
    const char* s_6f34b = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> video Buffer not enough, again
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde1d8
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xde200
    const char* s_6841d = "Android pixel encoder sendFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xde214
    _ZdlPv(...); // call imported API via PLT at 0xde23c
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xde260
    pthread_self(...); // call imported API via PLT at 0xde284
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde2a8
    pthread_self(...); // call imported API via PLT at 0xde2cc
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde2f0
    (*x8)(...); // indirect call at 0xde34c
    _ZdlPv(...); // call imported API via PLT at 0xde35c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xde384
    pthread_self(...); // call imported API via PLT at 0xde38c
    const char* s_8e214 = "[%s(%d)]:> (%ld):> Send data to codec context error![%s]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde3b0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xde3d8
    pthread_self(...); // call imported API via PLT at 0xde3e0
    const char* s_85638 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Send data to codec context error![%s]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde404
    pthread_self(...); // call imported API via PLT at 0xde42c
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde44c
    pthread_self(...); // call imported API via PLT at 0xde470
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde490
    (*x8)(...); // indirect call at 0xde4bc
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xde4c4
    av_gettime_relative(...); // call imported API via PLT at 0xde4e4
    av_get_time_base_q(...); // call imported API via PLT at 0xde508
    av_rescale_q(...); // call imported API via PLT at 0xde518
    pthread_self(...); // call imported API via PLT at 0xde540
    const char* s_75d16 = "[%s(%d)]:> (%ld):> packetQueue.put %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde564
    pthread_self(...); // call imported API via PLT at 0xde588
    const char* s_82d66 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde5ac
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xde5b8
    pthread_self(...); // call imported API via PLT at 0xde5e0
    const char* s_85683 = "[%s(%d)]:> (%ld):> packetQueue.put end %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde608
    pthread_self(...); // call imported API via PLT at 0xde62c
    const char* s_70f85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put end %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde654
    pthread_self(...); // call imported API via PLT at 0xde67c
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde6a4
    pthread_self(...); // call imported API via PLT at 0xde6c8
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde6f0
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xde714
    const char* s_856b0 = "Android pixel encoder receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xde728
    _ZdlPv(...); // call imported API via PLT at 0xde750
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xde774
    pthread_self(...); // call imported API via PLT at 0xde798
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde7bc
    pthread_self(...); // call imported API via PLT at 0xde7e0
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde804
    sub_D6E08(...); // call internal func at 0xde834
    _ZdlPv(...); // call imported API via PLT at 0xde844
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xde86c
    pthread_self(...); // call imported API via PLT at 0xde874
    const char* s_8e26c = "[%s(%d)]:> (%ld):> Encode data error![%s]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde898
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xde8c0
    pthread_self(...); // call imported API via PLT at 0xde8c8
    const char* s_80708 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode data error![%s]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde8ec
    (*x8)(...); // indirect call at 0xde918
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xde920
    pthread_self(...); // call imported API via PLT at 0xde948
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_78c08 = "[%s(%d)]:> (%ld):> input parameter error!"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xde970
    pthread_self(...); // call imported API via PLT at 0xde994
    const char* s_779a3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter error!
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xde9b8
    return a0;
    pthread_self(...); // call imported API via PLT at 0xdea10
    const char* s_78c46 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [start>>>][%d]AndroidVideoPixelStreamBase %p
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdea40
    pthread_self(...); // call imported API via PLT at 0xdea70
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c82e = "[%s(%d)]:> (%ld):> input parameter invalid!"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdea98
    pthread_self(...); // call imported API via PLT at 0xdeabc
    const char* s_8c85a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter invalid!
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdeae0
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0xdeae8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdeaf4
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdeb04
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdeb0c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdeb14
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdeb1c
    sub_D14D8(...); // call internal func at 0xdeb44
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xdeb4c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdeb54
    pthread_self(...); // call imported API via PLT at 0xdeb78
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b2c2 = "[%s(%d)]:> (%ld):> Encode thread force quit"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdeba0
    pthread_self(...); // call imported API via PLT at 0xdebc4
    const char* s_83e4e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode thread force quit
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdebe8
    (*x8)(...); // indirect call at 0xdec14
    (*x8)(...); // indirect call at 0xdec44
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xdec54
    const char* s_749f3 = "Android pixel encoder  send null frame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdec68
    _ZdlPv(...); // call imported API via PLT at 0xdec90
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdecb8
    pthread_self(...); // call imported API via PLT at 0xdecdc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_856dc = "[%s(%d)]:> (%ld):> [flush]Send data to codec context error![%s]"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xded08
    pthread_self(...); // call imported API via PLT at 0xded2c
    const char* s_68445 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [flush]Send data to codec context error![%s]
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xded54
    _ZdlPv(...); // call imported API via PLT at 0xded64
    void* g_1fda00 = (void*)0x1fda00; // global ref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    (*x8)(...); // indirect call at 0xdeda4
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xdeda8
    _Znwm(...); // call imported API via PLT at 0xdedbc
    (*x8)(...); // indirect call at 0xdede0
    av_gettime_relative(...); // call imported API via PLT at 0xdee00
    pthread_self(...); // call imported API via PLT at 0xdee3c
    const char* s_75d16 = "[%s(%d)]:> (%ld):> packetQueue.put %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdee60
    pthread_self(...); // call imported API via PLT at 0xdee84
    const char* s_82d66 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdeea8
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xdeeb4
    pthread_self(...); // call imported API via PLT at 0xdeedc
    const char* s_85683 = "[%s(%d)]:> (%ld):> packetQueue.put end %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdef04
    pthread_self(...); // call imported API via PLT at 0xdef28
    const char* s_70f85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put end %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdef50
    pthread_self(...); // call imported API via PLT at 0xdef78
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdefa0
    pthread_self(...); // call imported API via PLT at 0xdefc4
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdefec
    pthread_self(...); // call imported API via PLT at 0xdf01c
    const char* s_6f38f = "[%s(%d)]:> (%ld):> Flush android pixel Encoder end"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf03c
    pthread_self(...); // call imported API via PLT at 0xdf060
    const char* s_81926 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Flush android pixel Encoder end
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf080
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xdf09c
    const char* s_8ad28 = "android pixel flush receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdf0b0
    _ZdlPv(...); // call imported API via PLT at 0xdf0d8
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdf0fc
    pthread_self(...); // call imported API via PLT at 0xdf120
    const char* s_7d936 = "[%s(%d)]:> (%ld):> Flush android pixel Encoder error[%s]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf144
    pthread_self(...); // call imported API via PLT at 0xdf168
    const char* s_8f6e1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Flush android pixel Encoder error[%s]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf18c
    _ZdlPv(...); // call imported API via PLT at 0xdf19c
    (*x8)(...); // indirect call at 0xdf1c8
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdf1d0
    pthread_self(...); // call imported API via PLT at 0xdf1f8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf220
    pthread_self(...); // call imported API via PLT at 0xdf244
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf268
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdf270
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xdf280
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdf288
    (*x8)(...); // indirect call at 0xdf2e8
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0xdf2f0
    pthread_self(...); // call imported API via PLT at 0xdf318
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e2e0 = "[%s(%d)]:> (%ld):> [%d]android pixel encode thread exit! frameCnt %d"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdf34c
    pthread_self(...); // call imported API via PLT at 0xdf370
    const char* s_7c680 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]android pixel encode thread exit! frameCnt %d
"; // string xref
    const char* s_7b328 = "androidEncodePixelThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdf3a0
    _ZdlPv(...); // call imported API via PLT at 0xdf3b8
    _ZdlPv(...); // call imported API via PLT at 0xdf3d4
    _ZdlPv(...); // call imported API via PLT at 0xdf3ec
    _ZdlPv(...); // call imported API via PLT at 0xdf404
    (*x9)(...); // indirect call at 0xdf43c
    _ZdlPv(...); // call imported API via PLT at 0xdf454
    _ZdlPv(...); // call imported API via PLT at 0xdf470
    __cxa_begin_catch(...); // call imported API via PLT at 0xdf47c
    (*x8)(...); // indirect call at 0xdf48c
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xdf494
    __cxa_rethrow(...); // call imported API via PLT at 0xdf4ac
    __cxa_end_catch(...); // call imported API via PLT at 0xdf4b4
    sub_CEBC4(...); // call internal func at 0xdf4bc
    _ZdlPv(...); // call imported API via PLT at 0xdf4d0
    _ZdlPv(...); // call imported API via PLT at 0xdf4e8
    (*x9)(...); // indirect call at 0xdf52c
    __cxa_begin_catch(...); // call imported API via PLT at 0xdf534
    (*x8)(...); // indirect call at 0xdf544
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xdf54c
    __cxa_rethrow(...); // call imported API via PLT at 0xdf564
    __cxa_end_catch(...); // call imported API via PLT at 0xdf56c
    sub_CEBC4(...); // call internal func at 0xdf574
    sub_DC738(...); // call internal func at 0xdf580
    sub_DC738(...); // call internal func at 0xdf594
    sub_D0AB4(...); // call internal func at 0xdf5a4
    __stack_chk_fail(...); // call imported API via PLT at 0xdf5c4
}
