// Function: MMCodec::MediaRecorder::recordVideo(void*, double, std::__ndk1::function<void ()>)
// RVA: 0xe545c, Size: 868 bytes
int64_t _ZN7MMCodec13MediaRecorder11recordVideoEPvdNSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xe5504
    av_image_get_buffer_size(...); // call imported API via PLT at 0xe5518
    _ZN7MMCodec19AICodecSampleBuffer6createENS_22AICodecSampleMediaTypeE(...); // call imported API via PLT at 0xe5548
    _Znwm(...); // call imported API via PLT at 0xe5554
    _ZN7MMCodec22AICodecVideoDataBufferC1EmmNS_16VIDEO_PIX_FORMATENS_14ColorSpaceTypeE(...); // call imported API via PLT at 0xe5570
    _ZN7MMCodec19AICodecSampleBuffer13setDataBufferEPNS_17AICodecDataBufferE(...); // call imported API via PLT at 0xe557c
    _ZN7MMCodec19AICodecSampleBuffer24setPresentationTimestampEl(...); // call imported API via PLT at 0xe559c
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0xe55a4
    (*x9)(...); // indirect call at 0xe55d8
    (*x8)(...); // indirect call at 0xe55f8
    (*x8)(...); // indirect call at 0xe5624
    _ZN7MMCodec13MediaRecorder23recordVideoSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe5638
    (*x9)(...); // indirect call at 0xe5670
    return a0;
    pthread_self(...); // call imported API via PLT at 0xe56c8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_819e0 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> get image buffer failed %d"; // string xref
    const char* s_7d96f = "recordVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe56f8
    pthread_self(...); // call imported API via PLT at 0xe571c
    const char* s_7eb94 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> get image buffer failed %d
"; // string xref
    const char* s_7d96f = "recordVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe5748
    __stack_chk_fail(...); // call imported API via PLT at 0xe5760
    _ZdlPv(...); // call imported API via PLT at 0xe576c
    (*x9)(...); // indirect call at 0xe57a4
}
