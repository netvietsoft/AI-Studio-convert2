// Function: MMCodec::androidEncodeThread(void*)
// RVA: 0xdc788, Size: 5348 bytes
int64_t _ZN7MMCodec19androidEncodeThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdc7d4
    (*x8)(...); // indirect call at 0xdc86c
    pthread_self(...); // call imported API via PLT at 0xdc888
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_882d1 = "[%s(%d)]:> (%ld):> [start>>>][%d]OutMediaStreamParam %p"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdc8bc
    pthread_self(...); // call imported API via PLT at 0xdc8d8
    const char* s_8e296 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [start>>>][%d]OutMediaStreamParam %p
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdc908
    const char* s_78c32 = "androidEncodeThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0xdc93c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_78c08 = "[%s(%d)]:> (%ld):> input parameter error!"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdc964
    pthread_self(...); // call imported API via PLT at 0xdc980
    const char* s_779a3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter error!
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdc9a4
    return a0;
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0xdc9e4
    (*x8)(...); // indirect call at 0xdc9f8
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xdc9fc
    _Znwm(...); // call imported API via PLT at 0xdca10
    void* g_1fd910 = (void*)0x1fd910; // global ref
    (*x8)(...); // indirect call at 0xdca3c
    pthread_self(...); // call imported API via PLT at 0xdca64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83efa = "[%s(%d)]:> (%ld):> receivePacket need again"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdca88
    pthread_self(...); // call imported API via PLT at 0xdcaa4
    const char* s_69643 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> receivePacket need again
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdcac4
    av_gettime_relative(...); // call imported API via PLT at 0xdcae8
    av_get_time_base_q(...); // call imported API via PLT at 0xdcb08
    av_rescale_q(...); // call imported API via PLT at 0xdcb18
    pthread_self(...); // call imported API via PLT at 0xdcb48
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75d16 = "[%s(%d)]:> (%ld):> packetQueue.put %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcb70
    pthread_self(...); // call imported API via PLT at 0xdcb8c
    const char* s_82d66 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdcbb0
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xdcbbc
    pthread_self(...); // call imported API via PLT at 0xdcbdc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85683 = "[%s(%d)]:> (%ld):> packetQueue.put end %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcc08
    pthread_self(...); // call imported API via PLT at 0xdcc24
    const char* s_70f85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put end %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdcc4c
    pthread_self(...); // call imported API via PLT at 0xdcc6c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcc98
    pthread_self(...); // call imported API via PLT at 0xdccb4
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdccdc
    (*x8)(...); // indirect call at 0xdcd08
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdcd10
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xdcd28
    const char* s_6f32c = "Hardware receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdcd3c
    _ZdlPv(...); // call imported API via PLT at 0xdcd68
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdcd8c
    pthread_self(...); // call imported API via PLT at 0xdcda8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcdd0
    pthread_self(...); // call imported API via PLT at 0xdcdec
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdce10
    (*x8)(...); // indirect call at 0xdce68
    _ZdlPv(...); // call imported API via PLT at 0xdce78
    pthread_self(...); // call imported API via PLT at 0xdce94
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67316 = "[%s(%d)]:> (%ld):> Encode data error![%d]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcebc
    pthread_self(...); // call imported API via PLT at 0xdced8
    const char* s_6b9a7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode data error![%d]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdcefc
    pthread_self(...); // call imported API via PLT at 0xdcf28
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_69611 = "[%s(%d)]:> (%ld):> Get encode thread param error!"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcf50
    pthread_self(...); // call imported API via PLT at 0xdcf6c
    const char* s_7c600 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Get encode thread param error!
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xdcf98
    pthread_self(...); // call imported API via PLT at 0xdcfb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88309 = "[%s(%d)]:> (%ld):> Thread quit request"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdcfe0
    pthread_self(...); // call imported API via PLT at 0xdcffc
    const char* s_7d8b2 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Thread quit request
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0xdd03c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd064
    pthread_self(...); // call imported API via PLT at 0xdd080
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0xdd0b8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b2c2 = "[%s(%d)]:> (%ld):> Encode thread force quit"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd0e0
    pthread_self(...); // call imported API via PLT at 0xdd0fc
    const char* s_83e4e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Encode thread force quit
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd120
    (*x8)(...); // indirect call at 0xdd188
    (*x8)(...); // indirect call at 0xdd1b8
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xdd1c8
    const char* s_77a21 = "Hardware flush sendFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdd1dc
    _ZdlPv(...); // call imported API via PLT at 0xdd204
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdd22c
    pthread_self(...); // call imported API via PLT at 0xdd248
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd274
    pthread_self(...); // call imported API via PLT at 0xdd290
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd2b8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdd2e0
    pthread_self(...); // call imported API via PLT at 0xdd2e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_725d3 = "[%s(%d)]:> (%ld):> [flush %d]Send data to codec context error![%s]"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd318
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xdd340
    pthread_self(...); // call imported API via PLT at 0xdd348
    const char* s_69681 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [flush %d]Send data to codec context error![%s]
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd374
    _ZdlPv(...); // call imported API via PLT at 0xdd384
    const char* s_78c32 = "androidEncodeThread"; // string xref
    (*x8)(...); // indirect call at 0xdd3b4
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0xdd3b8
    _Znwm(...); // call imported API via PLT at 0xdd3cc
    void* g_1fd960 = (void*)0x1fd960; // global ref
    (*x8)(...); // indirect call at 0xdd3f8
    pthread_self(...); // call imported API via PLT at 0xdd420
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c956 = "[%s(%d)]:> (%ld):> video Buffer not enough, again"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd444
    pthread_self(...); // call imported API via PLT at 0xdd460
    const char* s_6f34b = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> video Buffer not enough, again
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd480
    pthread_self(...); // call imported API via PLT at 0xdd4c0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ce8a = "[%s(%d)]:> (%ld):> flush push packet %lld"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd4e8
    pthread_self(...); // call imported API via PLT at 0xdd504
    const char* s_75d3c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> flush push packet %lld
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd52c
    pthread_self(...); // call imported API via PLT at 0xdd548
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75d16 = "[%s(%d)]:> (%ld):> packetQueue.put %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd570
    pthread_self(...); // call imported API via PLT at 0xdd58c
    const char* s_82d66 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put %p
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd5b0
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(...); // call imported API via PLT at 0xdd5bc
    pthread_self(...); // call imported API via PLT at 0xdd5dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85683 = "[%s(%d)]:> (%ld):> packetQueue.put end %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd608
    pthread_self(...); // call imported API via PLT at 0xdd624
    const char* s_70f85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put end %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd64c
    pthread_self(...); // call imported API via PLT at 0xdd66c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c898 = "[%s(%d)]:> (%ld):> packetQueue.put error %p %d"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd698
    pthread_self(...); // call imported API via PLT at 0xdd6b4
    const char* s_88290 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packetQueue.put error %p %d
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd6dc
    pthread_self(...); // call imported API via PLT at 0xdd710
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8acff = "[%s(%d)]:> (%ld):> [Flush %d]Encoder end"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd73c
    pthread_self(...); // call imported API via PLT at 0xdd758
    const char* s_70fc4 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [Flush %d]Encoder end
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd780
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xdd794
    const char* s_7d8eb = "Hardware flush receivePacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xdd7a8
    _ZdlPv(...); // call imported API via PLT at 0xdd7d0
    _ZN7MMCodec13MediaRecorder12addErrorInfoEPKc(...); // call imported API via PLT at 0xdd7f4
    pthread_self(...); // call imported API via PLT at 0xdd810
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd838
    pthread_self(...); // call imported API via PLT at 0xdd854
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd878
    pthread_self(...); // call imported API via PLT at 0xdd894
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_818f7 = "[%s(%d)]:> (%ld):> [Flush %d]Encoder error[%d]"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd8c4
    pthread_self(...); // call imported API via PLT at 0xdd8e0
    const char* s_7eb4f = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [Flush %d]Encoder error[%d]
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd90c
    _ZdlPv(...); // call imported API via PLT at 0xdd91c
    (*x8)(...); // indirect call at 0xdd948
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdd950
    pthread_self(...); // call imported API via PLT at 0xdd970
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c5d5 = "[%s(%d)]:> (%ld):> acquire AVPacket failed"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdd998
    pthread_self(...); // call imported API via PLT at 0xdd9b4
    const char* s_806cb = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquire AVPacket failed
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xdd9d8
    (*x8)(...); // indirect call at 0xdda3c
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0xdda44
    pthread_self(...); // call imported API via PLT at 0xdda60
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d4f = "[%s(%d)]:> (%ld):> [%d]Encode thread exit! frameCnt %d"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xdda94
    pthread_self(...); // call imported API via PLT at 0xddab0
    const char* s_77a42 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]Encode thread exit! frameCnt %d
"; // string xref
    const char* s_78c32 = "androidEncodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xddae0
    _ZdlPv(...); // call imported API via PLT at 0xddaf8
    _ZdlPv(...); // call imported API via PLT at 0xddb10
    (*x9)(...); // indirect call at 0xddb4c
    _ZdlPv(...); // call imported API via PLT at 0xddb64
    _ZdlPv(...); // call imported API via PLT at 0xddb7c
    _ZdlPv(...); // call imported API via PLT at 0xddb98
    _ZdlPv(...); // call imported API via PLT at 0xddbb0
    __cxa_begin_catch(...); // call imported API via PLT at 0xddbb8
    (*x8)(...); // indirect call at 0xddbc8
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xddbd0
    __cxa_rethrow(...); // call imported API via PLT at 0xddbe4
    __cxa_end_catch(...); // call imported API via PLT at 0xddbec
    sub_CEBC4(...); // call internal func at 0xddbf4
    __cxa_begin_catch(...); // call imported API via PLT at 0xddbf8
    (*x8)(...); // indirect call at 0xddc08
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0xddc10
    __cxa_rethrow(...); // call imported API via PLT at 0xddc24
    __cxa_end_catch(...); // call imported API via PLT at 0xddc2c
    sub_CEBC4(...); // call internal func at 0xddc34
    sub_DC738(...); // call internal func at 0xddc4c
    __stack_chk_fail(...); // call imported API via PLT at 0xddc68
}
