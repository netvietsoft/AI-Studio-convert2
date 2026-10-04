// Function: MMCodec::HLSMuxer::writePacket(AVPacket*, bool)
// RVA: 0xd9c64, Size: 948 bytes
int64_t _ZN7MMCodec8HLSMuxer11writePacketEP8AVPacketb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_rescale_q(...); // call imported API via PLT at 0xd9cbc
    av_rescale_q(...); // call imported API via PLT at 0xd9cd4
    av_rescale_q(...); // call imported API via PLT at 0xd9cec
    av_interleaved_write_frame(...); // call imported API via PLT at 0xd9d28
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82d22 = "[%s(%d)]:> fail to write frame"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd9d6c
    const char* s_79fb7 = "%s/MTMV_AICodec: [%s(%d)]:> fail to write frame
"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    void* g_2010f1 = (void*)0x2010f1; // global ref
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0xd9de8
    realloc(...); // call imported API via PLT at 0xd9e14
    memcpy(...); // call imported API via PLT at 0xd9e2c
    void* g_2010e5 = (void*)0x2010e5; // global ref
    memcpy(...); // call imported API via PLT at 0xd9eb0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90aca = "[%s(%d)]:> realloc failed"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd9ef8
    const char* s_74951 = "%s/MTMV_AICodec: [%s(%d)]:> realloc failed
"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd9f34
    memcpy(...); // call imported API via PLT at 0xd9f48
    memcpy(...); // call imported API via PLT at 0xd9f60
    av_interleaved_write_frame(...); // call imported API via PLT at 0xd9f6c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82d22 = "[%s(%d)]:> fail to write frame"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd9fb8
    const char* s_79fb7 = "%s/MTMV_AICodec: [%s(%d)]:> fail to write frame
"; // string xref
    const char* s_7b2b6 = "writePacket"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd9ff4
    return a0;
}
