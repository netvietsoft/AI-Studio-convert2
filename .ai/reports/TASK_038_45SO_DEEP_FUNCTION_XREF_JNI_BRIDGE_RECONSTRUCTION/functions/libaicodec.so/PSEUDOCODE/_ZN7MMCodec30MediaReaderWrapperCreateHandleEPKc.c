// Function: MMCodec::MediaReaderWrapperCreateHandle(char const*)
// RVA: 0x18d538, Size: 288 bytes
int64_t _ZN7MMCodec30MediaReaderWrapperCreateHandleEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x18d550
    _ZN7MMCodec14AICodecContextC1Ev(...); // call imported API via PLT at 0x18d558
    _Znwm(...); // call imported API via PLT at 0x18d560
    _ZN7MMCodec13MTMediaReaderC1EPKcPKhm(...); // call imported API via PLT at 0x18d574
    _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE(...); // call imported API via PLT at 0x18d580
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_79d4d = "[%s(%d)]:> create reader %p with context %p"; // string xref
    const char* s_79d79 = "MediaReaderWrapperCreateHandle"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18d5c8
    const char* s_6cc6f = "%s/MTMV_AICodec: [%s(%d)]:> create reader %p with context %p
"; // string xref
    const char* s_79d79 = "MediaReaderWrapperCreateHandle"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18d60c
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x18d614
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x18d638
    _ZdlPv(...); // call imported API via PLT at 0x18d64c
}
