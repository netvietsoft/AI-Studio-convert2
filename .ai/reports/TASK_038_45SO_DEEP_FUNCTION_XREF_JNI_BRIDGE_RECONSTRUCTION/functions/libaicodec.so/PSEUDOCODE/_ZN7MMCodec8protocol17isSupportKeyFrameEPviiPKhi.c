// Function: MMCodec::protocol::isSupportKeyFrame(void*, int, int, unsigned char const*, int)
// RVA: 0x1728a4, Size: 696 bytes
int64_t _ZN7MMCodec8protocol17isSupportKeyFrameEPviiPKhi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mm_decode_nal_units(...); // call imported API via PLT at 0x1728cc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c1ad = "[%s(%d)]:> HEVC:unsupported key frame:%s"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17295c
    const char* s_76e73 = "%s/MTMV_AICodec: [%s(%d)]:> HEVC:unsupported key frame:%s
"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    return a0;
    return a0;
    const char* s_79b7e = "h264_nal_unit_unknown";
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_69202 = "[%s(%d)]:> AVC:unsupported key frame:%s"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x172a20
    const char* s_79b7e = "h264_nal_unit_unknown";
    const char* s_7220f = "%s/MTMV_AICodec: [%s(%d)]:> AVC:unsupported key frame:%s
"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x172a7c
    return a0;
    const char* s_84d5b = "hevc_nal_unit_unknown"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7004e = "[%s(%d)]:> HEVC:unidentifiable key frame:%s"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x172aec
    const char* s_84d5b = "hevc_nal_unit_unknown"; // string xref
    const char* s_8a970 = "%s/MTMV_AICodec: [%s(%d)]:> HEVC:unidentifiable key frame:%s
"; // string xref
    const char* s_919cb = "isSupportKeyFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x172b48
    return a0;
}
