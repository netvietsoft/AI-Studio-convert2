// Function: MMCodec::VideoStream::sendData(unsigned char**, unsigned long, unsigned long*, long, std::__ndk1::function<void ()>)
// RVA: 0xd7374, Size: 2772 bytes
int64_t _ZN7MMCodec11VideoStream8sendDataEPPhmPmlNSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0xd73e0
    (*x8)(...); // indirect call at 0xd7408
    _ZN7MMCodec14AICodecContext14acquireAVFrameEv(...); // call imported API via PLT at 0xd740c
    _Znwm(...); // call imported API via PLT at 0xd741c
    void* g_1fd820 = (void*)0x1fd820; // global ref
    (*x8)(...); // indirect call at 0xd745c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xd7464
    av_buffer_pool_init(...); // call imported API via PLT at 0xd7478
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd74bc
    pthread_self(...); // call imported API via PLT at 0xd74c4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_72599 = "[%s(%d)]:> [VideoStream(%p)](%ld):> Fill image error![%s]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd74f4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd751c
    pthread_self(...); // call imported API via PLT at 0xd7524
    const char* s_8f66b = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> Fill image error![%s]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd7550
    pthread_self(...); // call imported API via PLT at 0xd7578
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_75c53 = "[%s(%d)]:> [VideoStream(%p)](%ld):> encoder didn't start"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd75a4
    pthread_self(...); // call imported API via PLT at 0xd75c8
    const char* s_8ac8d = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> encoder didn't start
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd75f0
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xd761c
    pthread_self(...); // call imported API via PLT at 0xd7624
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6a880 = "[%s(%d)]:> [VideoStream(%p)](%ld):> encode thread state is invalid:%d"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7654
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xd767c
    pthread_self(...); // call imported API via PLT at 0xd7684
    const char* s_82cca = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> encode thread state is invalid:%d
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd76b0
    (*x8)(...); // indirect call at 0xd76c8
    (*x8)(...); // indirect call at 0xd76f0
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xd76f8
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd7754
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6ce11 = "[%s(%d)]:> [VideoStream(%p)](%ld):> acquireAVFrame error!"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7780
    const char* s_7254d = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> acquireAVFrame error!
"; // string xref
    pthread_self(...); // call imported API via PLT at 0xd77b0
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd77d4
    av_buffer_pool_get(...); // call imported API via PLT at 0xd77e0
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd77f4
    const char* s_72040 = "le %p, drop last one video frame %lld, ref time %lld"; // string xref
    av_image_fill_arrays(...); // call imported API via PLT at 0xd7828
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd7834
    av_get_time_base_q(...); // call imported API via PLT at 0xd7858
    av_rescale_q(...); // call imported API via PLT at 0xd786c
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE3putERKS4_(...); // call imported API via PLT at 0xd7894
    pthread_self(...); // call imported API via PLT at 0xd78bc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6ce4b = "[%s(%d)]:> [VideoStream(%p)](%ld):> av_buffer_pool_init failed"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd78e8
    const char* s_7c4c9 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> av_buffer_pool_init failed
"; // string xref
    pthread_self(...); // call imported API via PLT at 0xd7930
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6b948 = "[%s(%d)]:> [VideoStream(%p)](%ld):> av_buffer_pool_get failed"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd795c
    const char* s_7d825 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> av_buffer_pool_get failed
"; // string xref
    memcpy(...); // call imported API via PLT at 0xd79c4
    memcpy(...); // call imported API via PLT at 0xd79e8
    _ZN7MMCodec19getVideoPlaneNumberENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd79f4
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0xd7a18
    _ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb(...); // call imported API via PLT at 0xd7a28
    _ZN7MMCodec15VideoFrameUtils13convertFormatEPKPKhPKimiiiiPPhPiRm(...); // call imported API via PLT at 0xd7a54
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd7a74
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd7a88
    sws_getContext(...); // call imported API via PLT at 0xd7aac
    sws_getCoefficients(...); // call imported API via PLT at 0xd7ab8
    sws_setColorspaceDetails(...); // call imported API via PLT at 0xd7adc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8068e = "[%s(%d)]:> sws_setColorspaceDetails error."; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7b20
    const char* s_7d875 = "%s/MTMV_AICodec: [%s(%d)]:> sws_setColorspaceDetails error.
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd7b5c
    sws_scale(...); // call imported API via PLT at 0xd7b7c
    pthread_self(...); // call imported API via PLT at 0xd7ba8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c51a = "[%s(%d)]:> [VideoStream(%p)](%ld):> convertFormat failed %d"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7bd8
    pthread_self(...); // call imported API via PLT at 0xd7bfc
    const char* s_75c8c = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> convertFormat failed %d
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd7c28
    pthread_self(...); // call imported API via PLT at 0xd7c50
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_89d09 = "[%s(%d)]:> [VideoStream(%p)](%ld):> getVideoPlaneNumber failed %d"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7c80
    pthread_self(...); // call imported API via PLT at 0xd7ca4
    const char* s_79f3b = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> getVideoPlaneNumber failed %d
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd7cd0
    sub_1B17E0(...); // call internal func at 0xd7d3c
    sub_1B1444(...); // call internal func at 0xd7d88
    sub_1972F4(...); // call internal func at 0xd7dc8
    __cxa_begin_catch(...); // call imported API via PLT at 0xd7de0
    (*x8)(...); // indirect call at 0xd7df0
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0xd7df8
    __cxa_rethrow(...); // call imported API via PLT at 0xd7e0c
    __cxa_end_catch(...); // call imported API via PLT at 0xd7e14
    sub_CEBC4(...); // call internal func at 0xd7e1c
    sub_D0AB4(...); // call internal func at 0xd7e28
    __stack_chk_fail(...); // call imported API via PLT at 0xd7e44
}
