// Function: MMCodec::PCMTransfer::read(unsigned char**, int*, int)
// RVA: 0x16a5e4, Size: 1016 bytes
int64_t _ZN7MMCodec11PCMTransfer4readEPPhPii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_audio_fifo_size(...); // call imported API via PLT at 0x16a628
    _ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x16a66c
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x16a680
    _Znwm(...); // call imported API via PLT at 0x16a69c
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0x16a6ac
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x16a6bc
    memset(...); // call imported API via PLT at 0x16a6d4
    av_samples_fill_arrays(...); // call imported API via PLT at 0x16a700
    av_audio_fifo_write(...); // call imported API via PLT at 0x16a718
    av_audio_fifo_read(...); // call imported API via PLT at 0x16a730
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79b5f = "[%s(%d)]:> read samples failed"; // string xref
    const char* s_753fe = "read"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a77c
    const char* s_7f81f = "%s/MTMV_AICodec: [%s(%d)]:> read samples failed
"; // string xref
    const char* s_753fe = "read"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a7b8
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x16a7c4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x16a7d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a5ef = "[%s(%d)]:> alloc buffer failed"; // string xref
    const char* s_753fe = "read"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a830
    const char* s_75714 = "%s/MTMV_AICodec: [%s(%d)]:> alloc buffer failed
"; // string xref
    const char* s_753fe = "read"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a86c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_735e2 = "[%s(%d)]:> fill array failed"; // string xref
    const char* s_753fe = "read"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a8b4
    const char* s_87bff = "%s/MTMV_AICodec: [%s(%d)]:> fill array failed
"; // string xref
    const char* s_753fe = "read"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a8f0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6817e = "[%s(%d)]:> write samples failed"; // string xref
    const char* s_753fe = "read"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a938
    const char* s_76e41 = "%s/MTMV_AICodec: [%s(%d)]:> write samples failed
"; // string xref
    const char* s_753fe = "read"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a974
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x16a9cc
    __stack_chk_fail(...); // call imported API via PLT at 0x16a9d8
}
