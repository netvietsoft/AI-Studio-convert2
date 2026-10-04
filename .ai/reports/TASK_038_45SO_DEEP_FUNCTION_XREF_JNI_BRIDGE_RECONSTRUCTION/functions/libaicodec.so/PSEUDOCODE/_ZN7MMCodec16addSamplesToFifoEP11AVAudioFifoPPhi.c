// Function: MMCodec::addSamplesToFifo(AVAudioFifo*, unsigned char**, int)
// RVA: 0xec20c, Size: 180 bytes
int64_t _ZN7MMCodec16addSamplesToFifoEP11AVAudioFifoPPhi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_audio_fifo_write(...); // call imported API via PLT at 0xec21c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f845 = "[%s(%d)]:> Audio fifo write data err![%d]
"; // string xref
    const char* s_90bc2 = "addSamplesToFifo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xec26c
    const char* s_86ede = "%s/MTMV_AICodec: [%s(%d)]:> Audio fifo write data err![%d]

"; // string xref
    const char* s_90bc2 = "addSamplesToFifo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xec2ac
    return a0;
}
