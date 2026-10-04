// Function: MMCodec::MediaRecorderWrapperGetCVPixelBuffer(void*)
// RVA: 0x195d24, Size: 192 bytes
int64_t _ZN7MMCodec36MediaRecorderWrapperGetCVPixelBufferEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder24getRenderablePixelBufferEv(...); // call imported API via PLT at 0x195d28
    return a0;
    const char* s_8ab04 = "MediaRecorderWrapperGetCVPixelBuffer"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x195d94
    const char* s_8ab04 = "MediaRecorderWrapperGetCVPixelBuffer"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x195dd4
    return a0;
}
