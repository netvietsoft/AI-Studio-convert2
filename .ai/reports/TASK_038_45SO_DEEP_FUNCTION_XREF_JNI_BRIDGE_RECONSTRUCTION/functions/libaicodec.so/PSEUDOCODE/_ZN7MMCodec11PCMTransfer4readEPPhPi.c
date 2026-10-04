// Function: MMCodec::PCMTransfer::read(unsigned char**, int*)
// RVA: 0x16a434, Size: 432 bytes
int64_t _ZN7MMCodec11PCMTransfer4readEPPhPi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_audio_fifo_size(...); // call imported API via PLT at 0x16a45c
    return a0;
    return a0;
    return a0;
    _ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x16a4cc
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x16a4d8
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x16a4f0
    av_audio_fifo_read(...); // call imported API via PLT at 0x16a510
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79b5f = "[%s(%d)]:> read samples failed"; // string xref
    const char* s_753fe = "read"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a55c
    const char* s_7f81f = "%s/MTMV_AICodec: [%s(%d)]:> read samples failed
"; // string xref
    const char* s_753fe = "read"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a598
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x16a5a4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x16a5b0
    return a0;
}
