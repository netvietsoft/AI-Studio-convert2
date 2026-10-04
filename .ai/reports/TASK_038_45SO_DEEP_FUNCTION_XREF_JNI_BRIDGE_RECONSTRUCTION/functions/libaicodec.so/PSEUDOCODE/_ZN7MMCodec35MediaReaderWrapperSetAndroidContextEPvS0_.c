// Function: MMCodec::MediaReaderWrapperSetAndroidContext(void*, void*)
// RVA: 0x18d748, Size: 192 bytes
int64_t _ZN7MMCodec35MediaReaderWrapperSetAndroidContextEPvS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x18d75c
    _ZN7MMCodec13AICodecGlobal17setAndroidContextEP8_jobject(...); // call imported API via PLT at 0x18d76c
    const char* s_693d9 = "MediaReaderWrapperSetAndroidContext"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18d7b0
    const char* s_693d9 = "MediaReaderWrapperSetAndroidContext"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18d7f8
    return a0;
}
