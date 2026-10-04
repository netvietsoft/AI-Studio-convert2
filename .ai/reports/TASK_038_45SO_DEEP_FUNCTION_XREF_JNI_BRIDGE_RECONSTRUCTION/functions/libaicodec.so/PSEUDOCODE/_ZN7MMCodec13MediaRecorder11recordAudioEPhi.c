// Function: MMCodec::MediaRecorder::recordAudio(unsigned char*, int)
// RVA: 0xe47a8, Size: 188 bytes
int64_t _ZN7MMCodec13MediaRecorder11recordAudioEPhi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19AICodecSampleBuffer6createENS_22AICodecSampleMediaTypeE(...); // call imported API via PLT at 0xe47e0
    _ZN7MMCodec28AICodecFFmpegAudioDataBuffer6createEPKv(...); // call imported API via PLT at 0xe47f4
    _ZN7MMCodec19AICodecSampleBuffer13setDataBufferEPNS_17AICodecDataBufferE(...); // call imported API via PLT at 0xe4800
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0xe480c
    (*x8)(...); // indirect call at 0xe4820
    _ZN7MMCodec13MediaRecorder23recordAudioSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe4834
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xe4860
}
