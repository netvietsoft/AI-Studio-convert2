// Function: MMCodec::MediaRecorderWrapperReleaseHandle(void**)
// RVA: 0x194b1c, Size: 212 bytes
int64_t _ZN7MMCodec33MediaRecorderWrapperReleaseHandleEPPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorderD1Ev(...); // call imported API via PLT at 0x194b3c
    _ZdlPv(...); // call imported API via PLT at 0x194b44
    return a0;
    const char* s_6a7ba = "MediaRecorderWrapperReleaseHandle"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_86c1b = "[%s(%d)]:> MediaRecorderWrapper %s handleAddr is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x194b9c
    const char* s_6a7ba = "MediaRecorderWrapperReleaseHandle"; // string xref
    const char* s_9094d = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handleAddr is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x194bdc
    return a0;
}
