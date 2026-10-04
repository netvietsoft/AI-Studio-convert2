// Function: MMCodec::releaseMediaReaderHandle(void**)
// RVA: 0x1747ac, Size: 192 bytes
int64_t _ZN7MMCodec24releaseMediaReaderHandleEPPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReaderD1Ev(...); // call imported API via PLT at 0x1747cc
    _ZdlPv(...); // call imported API via PLT at 0x1747d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79c1a = "[%s(%d)]:> release reader %p"; // string xref
    const char* s_700a6 = "releaseMediaReaderHandle"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x174818
    const char* s_7afc4 = "%s/MTMV_AICodec: [%s(%d)]:> release reader %p
"; // string xref
    const char* s_700a6 = "releaseMediaReaderHandle"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x174858
    return a0;
}
