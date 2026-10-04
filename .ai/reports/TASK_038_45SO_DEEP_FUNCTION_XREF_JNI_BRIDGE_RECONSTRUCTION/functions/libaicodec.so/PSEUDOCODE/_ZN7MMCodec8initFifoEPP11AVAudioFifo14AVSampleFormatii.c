// Function: MMCodec::initFifo(AVAudioFifo**, AVSampleFormat, int, int)
// RVA: 0xec13c, Size: 208 bytes
int64_t _ZN7MMCodec8initFifoEPP11AVAudioFifo14AVSampleFormatii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_audio_fifo_alloc(...); // call imported API via PLT at 0xec15c
    return a0;
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e372 = "[%s(%d)]:> Alloc audio fifo err!
"; // string xref
    const char* s_8af54 = "initFifo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xec1bc
    const char* s_77ac7 = "%s/MTMV_AICodec: [%s(%d)]:> Alloc audio fifo err!

"; // string xref
    const char* s_8af54 = "initFifo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xec1f8
    return a0;
}
