// Function: MMCodec::MediaReaderWrapperResume(void*)
// RVA: 0x19097c, Size: 172 bytes
int64_t _ZN7MMCodec24MediaReaderWrapperResumeEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader6resumeEv(...); // call imported API via PLT at 0x190988
    return a0;
    const char* s_80443 = "MediaReaderWrapperResume"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1909d8
    const char* s_80443 = "MediaReaderWrapperResume"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190a18
    return a0;
}
