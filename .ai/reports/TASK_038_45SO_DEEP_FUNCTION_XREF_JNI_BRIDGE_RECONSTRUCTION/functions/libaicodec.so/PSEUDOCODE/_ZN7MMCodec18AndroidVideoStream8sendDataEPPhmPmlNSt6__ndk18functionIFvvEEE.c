// Function: MMCodec::AndroidVideoStream::sendData(unsigned char**, unsigned long, unsigned long*, long, std::__ndk1::function<void ()>)
// RVA: 0xf8424, Size: 3020 bytes
int64_t _ZN7MMCodec18AndroidVideoStream8sendDataEPPhmPmlNSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0xf8488
    _ZNK7MMCodec14AndroidEncoder14getEncoderTypeEv(...); // call imported API via PLT at 0xf84a0
    (*x8)(...); // indirect call at 0xf84c8
    _ZN7MMCodec14AICodecContext14acquireAVFrameEv(...); // call imported API via PLT at 0xf84cc
    _Znwm(...); // call imported API via PLT at 0xf84dc
    void* g_1fe278 = (void*)0x1fe278; // global ref
    (*x8)(...); // indirect call at 0xf851c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xf8524
    av_buffer_pool_init(...); // call imported API via PLT at 0xf8538
    av_buffer_pool_get(...); // call imported API via PLT at 0xf8544
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf8558
    av_image_fill_arrays(...); // call imported API via PLT at 0xf8574
    _ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_(...); // call imported API via PLT at 0xf8594
    memcpy(...); // call imported API via PLT at 0xf85f4
    pthread_self(...); // call imported API via PLT at 0xf862c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88509 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> in parameter is invalid"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8658
    pthread_self(...); // call imported API via PLT at 0xf867c
    const char* s_713b8 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> in parameter is invalid
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf86a4
    return a0;
    pthread_self(...); // call imported API via PLT at 0xf8700
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_675e8 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encoder didn't alloc"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf872c
    pthread_self(...); // call imported API via PLT at 0xf8750
    const char* s_6e420 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encoder didn't alloc
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf8798
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a44f = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encoder didn't start"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf87c4
    pthread_self(...); // call imported API via PLT at 0xf87e8
    const char* s_75fb6 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encoder didn't start
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf8830
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xf8840
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90d48 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encode thread state is invalid:%d"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8870
    pthread_self(...); // call imported API via PLT at 0xf8894
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xf88a4
    const char* s_7b6bb = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> encode thread state is invalid:%d
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf88d0
    (*x8)(...); // indirect call at 0xf88f4
    pthread_self(...); // call imported API via PLT at 0xf8920
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84148 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> acquireAVFrame error!"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf894c
    const char* s_74be8 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> acquireAVFrame error!
"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf899c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e472 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_buffer_pool_get failed"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf89c8
    const char* s_8b133 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_buffer_pool_get failed
"; // string xref
    (*x8)(...); // indirect call at 0xf8a08
    (*x8)(...); // indirect call at 0xf8a30
    (*x8)(...); // indirect call at 0xf8a60
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf8a8c
    pthread_self(...); // call imported API via PLT at 0xf8a94
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72717 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Fill image error![%s]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8ac4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf8aec
    pthread_self(...); // call imported API via PLT at 0xf8af4
    const char* s_74c3b = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Fill image error![%s]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8b20
    pthread_self(...); // call imported API via PLT at 0xf8b48
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c948 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_buffer_pool_init failed"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8b74
    const char* s_7140d = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_buffer_pool_init failed
"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf8ba4
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8bc8
    (*x8)(...); // indirect call at 0xf8be0
    (*x8)(...); // indirect call at 0xf8c08
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xf8c10
    pthread_self(...); // call imported API via PLT at 0xf8c38
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6bc8a = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> getPlaneWidthAndHeightWithFormat failed"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8c64
    pthread_self(...); // call imported API via PLT at 0xf8c88
    const char* s_6e4b7 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> getPlaneWidthAndHeightWithFormat failed
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8cb0
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf8cbc
    av_get_time_base_q(...); // call imported API via PLT at 0xf8ccc
    av_rescale_q(...); // call imported API via PLT at 0xf8ce0
    pthread_self(...); // call imported API via PLT at 0xf8d20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77c28 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> put frame %p"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8d50
    pthread_self(...); // call imported API via PLT at 0xf8d74
    const char* s_72758 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> put frame %p
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8da0
    _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE3putERKS4_(...); // call imported API via PLT at 0xf8dac
    pthread_self(...); // call imported API via PLT at 0xf8dc8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89fd1 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> put frame end %p"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8df8
    pthread_self(...); // call imported API via PLT at 0xf8e14
    const char* s_8cc72 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> put frame end %p
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8e40
    memcpy(...); // call imported API via PLT at 0xf8e50
    memcpy(...); // call imported API via PLT at 0xf8eac
    memcpy(...); // call imported API via PLT at 0xf8ecc
    memcpy(...); // call imported API via PLT at 0xf8f28
    memcpy(...); // call imported API via PLT at 0xf8f48
    (*x9)(...); // indirect call at 0xf8f80
    __cxa_begin_catch(...); // call imported API via PLT at 0xf8f88
    (*x8)(...); // indirect call at 0xf8f98
    _ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame(...); // call imported API via PLT at 0xf8fa0
    __cxa_rethrow(...); // call imported API via PLT at 0xf8fb4
    __cxa_end_catch(...); // call imported API via PLT at 0xf8fbc
    sub_CEBC4(...); // call internal func at 0xf8fc4
    sub_D0AB4(...); // call internal func at 0xf8fd0
    __stack_chk_fail(...); // call imported API via PLT at 0xf8fec
}
