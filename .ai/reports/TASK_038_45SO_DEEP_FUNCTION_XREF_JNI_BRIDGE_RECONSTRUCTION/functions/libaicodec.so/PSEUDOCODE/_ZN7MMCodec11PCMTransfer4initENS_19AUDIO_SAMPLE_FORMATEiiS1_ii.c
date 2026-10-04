// Function: MMCodec::PCMTransfer::init(MMCodec::AUDIO_SAMPLE_FORMAT, int, int, MMCodec::AUDIO_SAMPLE_FORMAT, int, int)
// RVA: 0x169f48, Size: 236 bytes
int64_t _ZN7MMCodec11PCMTransfer4initENS_19AUDIO_SAMPLE_FORMATEiiS1_ii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x169f8c
    av_audio_fifo_free(...); // call imported API via PLT at 0x169f9c
    _ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x169fb4
    _Znwm(...); // call imported API via PLT at 0x169fc0
    _ZN7MMCodec10MTResampleC1Ev(...); // call imported API via PLT at 0x169fc8
    _ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x169fd4
    _ZN7MMCodec10MTResample4initE14AVSampleFormatiiS1_ii(...); // call imported API via PLT at 0x169fec
    av_audio_fifo_alloc(...); // call imported API via PLT at 0x169ffc
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x16a028
}
