// Function: MMCodec::PCMTransfer::write(unsigned char**, int, int)
// RVA: 0x16a03c, Size: 1016 bytes
int64_t _ZN7MMCodec11PCMTransfer5writeEPPhii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x16a0c4
    _ZN7MMCodec10MTResample35getNextOutBufferSizeWithWantSamplesEi(...); // call imported API via PLT at 0x16a0e8
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x16a104
    _ZN7MMCodec10MTResample8resampleEPPhiS1_Rmi(...); // call imported API via PLT at 0x16a128
    av_samples_fill_arrays(...); // call imported API via PLT at 0x16a158
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_735e2 = "[%s(%d)]:> fill array failed"; // string xref
    const char* s_6e8cb = "write"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a1a0
    const char* s_87bff = "%s/MTMV_AICodec: [%s(%d)]:> fill array failed
"; // string xref
    const char* s_6e8cb = "write"; // string xref
    memcpy(...); // call imported API via PLT at 0x16a1f4
    av_audio_fifo_write(...); // call imported API via PLT at 0x16a204
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6817e = "[%s(%d)]:> write samples failed"; // string xref
    const char* s_6e8cb = "write"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a24c
    const char* s_76e41 = "%s/MTMV_AICodec: [%s(%d)]:> write samples failed
"; // string xref
    const char* s_6e8cb = "write"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a288
    _ZN7MMCodec10MTResample40getNextOutBufferSizeWithNextInputSamplesEi(...); // call imported API via PLT at 0x16a29c
    _Znwm(...); // call imported API via PLT at 0x16a2b4
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0x16a2c4
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x16a2d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a5ef = "[%s(%d)]:> alloc buffer failed"; // string xref
    const char* s_6e8cb = "write"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a318
    const char* s_75714 = "%s/MTMV_AICodec: [%s(%d)]:> alloc buffer failed
"; // string xref
    const char* s_6e8cb = "write"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a354
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e672 = "[%s(%d)]:> resample failed"; // string xref
    const char* s_6e8cb = "write"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16a39c
    const char* s_81578 = "%s/MTMV_AICodec: [%s(%d)]:> resample failed
"; // string xref
    const char* s_6e8cb = "write"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16a3d8
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x16a414
    __stack_chk_fail(...); // call imported API via PLT at 0x16a430
}
