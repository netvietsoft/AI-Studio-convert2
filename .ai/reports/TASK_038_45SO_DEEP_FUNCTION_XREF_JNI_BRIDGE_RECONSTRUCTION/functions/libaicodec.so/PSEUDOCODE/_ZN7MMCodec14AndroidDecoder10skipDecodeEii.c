// Function: MMCodec::AndroidDecoder::skipDecode(int, int)
// RVA: 0xfb610, Size: 388 bytes
int64_t _ZN7MMCodec14AndroidDecoder10skipDecodeEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec8protocol11shift_countEh(...); // call imported API via PLT at 0xfb648
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_714b9 = "[%s(%d)]:> [HEVC]:unarchieveable skip rate, set skip rate to default"; // string xref
    const char* s_8e61e = "skipDecode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xfb6a4
    const char* s_8091a = "%s/MTMV_AICodec: [%s(%d)]:> [HEVC]:unarchieveable skip rate, set skip rate to default
"; // string xref
    const char* s_8e61e = "skipDecode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xfb6e0
    return a0;
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8703e = "[%s(%d)]:> invalid skip rate, fail to set skip mode"; // string xref
    const char* s_8e61e = "skipDecode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xfb74c
    const char* s_6d1b7 = "%s/MTMV_AICodec: [%s(%d)]:> invalid skip rate, fail to set skip mode
"; // string xref
    const char* s_8e61e = "skipDecode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xfb790
}
