// Function: MMCodec::AndroidDecoder::getBufferSize(AVFrame*)
// RVA: 0xfb410, Size: 504 bytes
int64_t _ZN7MMCodec14AndroidDecoder13getBufferSizeEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19getVideoOuterFormatE13AVPixelFormat(...); // call imported API via PLT at 0xfb44c
    _ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_(...); // call imported API via PLT at 0xfb45c
    __stack_chk_fail(...); // call imported API via PLT at 0xfb54c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_68677 = "[%s(%d)]:> getPlaneWidthAndHeightWithFormat failed"; // string xref
    const char* s_78e9a = "getBufferSize"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xfb58c
    const char* s_686aa = "%s/MTMV_AICodec: [%s(%d)]:> getPlaneWidthAndHeightWithFormat failed
"; // string xref
    const char* s_78e9a = "getBufferSize"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xfb5c8
    return a0;
}
