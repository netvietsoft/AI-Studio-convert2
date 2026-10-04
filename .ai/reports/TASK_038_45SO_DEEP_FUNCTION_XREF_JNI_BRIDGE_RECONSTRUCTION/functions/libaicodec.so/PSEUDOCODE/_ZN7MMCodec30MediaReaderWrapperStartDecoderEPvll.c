// Function: MMCodec::MediaReaderWrapperStartDecoder(void*, long, long)
// RVA: 0x190ad4, Size: 320 bytes
int64_t _ZN7MMCodec30MediaReaderWrapperStartDecoderEPvll(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader17getAICodecContextEv(...); // call imported API via PLT at 0x190af4
    _Znwm(...); // call imported API via PLT at 0x190b00
    _ZN7MMCodec14AICodecContextC1Ev(...); // call imported API via PLT at 0x190b08
    _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE(...); // call imported API via PLT at 0x190b14
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x190b1c
    _ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll(...); // call imported API via PLT at 0x190b3c
    return a0;
    const char* s_75992 = "MediaReaderWrapperStartDecoder"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190ba8
    const char* s_75992 = "MediaReaderWrapperStartDecoder"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190be8
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x190c08
}
