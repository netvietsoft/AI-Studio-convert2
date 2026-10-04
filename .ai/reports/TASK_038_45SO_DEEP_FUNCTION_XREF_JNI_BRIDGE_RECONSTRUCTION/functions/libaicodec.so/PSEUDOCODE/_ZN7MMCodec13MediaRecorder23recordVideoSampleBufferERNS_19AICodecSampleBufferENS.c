// Function: MMCodec::MediaRecorder::recordVideoSampleBuffer(MMCodec::AICodecSampleBuffer&, std::__ndk1::function<void ()>)
// RVA: 0xe4f80, Size: 1244 bytes
int64_t _ZN7MMCodec13MediaRecorder23recordVideoSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec19AICodecSampleBuffer12getMediaTypeEv(...); // call imported API via PLT at 0xe4fc4
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0xe4fd4
    pthread_self(...); // call imported API via PLT at 0xe500c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7a0ca = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid state"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe5038
    pthread_self(...); // call imported API via PLT at 0xe505c
    const char* s_673ea = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid state
"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe5084
    pthread_self(...); // call imported API via PLT at 0xe50b0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8caa1 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid media type"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe50dc
    pthread_self(...); // call imported API via PLT at 0xe5100
    const char* s_684bc = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid media type
"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe5128
    pthread_self(...); // call imported API via PLT at 0xe515c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7a07c = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> get null data buffer form sample buffer"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe5188
    pthread_self(...); // call imported API via PLT at 0xe51ac
    const char* s_711c2 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> get null data buffer form sample buffer
"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe51d4
    (*x8)(...); // indirect call at 0xe5200
    (*x8)(...); // indirect call at 0xe5228
    (*x8)(...); // indirect call at 0xe5244
    (*x8)(...); // indirect call at 0xe5268
    _ZNK7MMCodec19AICodecSampleBuffer24getPresentationTimestampEv(...); // call imported API via PLT at 0xe5274
    (*x8)(...); // indirect call at 0xe529c
    (*x9)(...); // indirect call at 0xe52d0
    _ZN7MMCodec14OutMediaHandle8sendDataEPPhmPmlNS_11MediaType_tENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe52f4
    (*x8)(...); // indirect call at 0xe5324
    pthread_self(...); // call imported API via PLT at 0xe5354
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6cec7 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to send frame to RecorderHandle %d"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe5384
    pthread_self(...); // call imported API via PLT at 0xe53a8
    const char* s_84046 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to send frame to RecorderHandle %d
"; // string xref
    const char* s_77a8b = "recordVideoSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe53d4
    return a0;
    (*x9)(...); // indirect call at 0xe543c
    __stack_chk_fail(...); // call imported API via PLT at 0xe5458
}
