// Function: MMCodec::MediaRecorderWrapperSetAndroidContext(void*, void*)
// RVA: 0x194bf0, Size: 192 bytes
int64_t _ZN7MMCodec37MediaRecorderWrapperSetAndroidContextEPvS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x194c04
    _ZN7MMCodec13AICodecGlobal17setAndroidContextEP8_jobject(...); // call imported API via PLT at 0x194c14
    const char* s_8c5e6 = "MediaRecorderWrapperSetAndroidContext"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x194c58
    const char* s_8c5e6 = "MediaRecorderWrapperSetAndroidContext"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x194ca0
    return a0;
}
