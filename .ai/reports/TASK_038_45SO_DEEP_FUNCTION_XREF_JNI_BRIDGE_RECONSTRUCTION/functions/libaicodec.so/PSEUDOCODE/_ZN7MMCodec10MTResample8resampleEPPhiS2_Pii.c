// Function: MMCodec::MTResample::resample(unsigned char**, int, unsigned char**, int*, int)
// RVA: 0x168bec, Size: 636 bytes
int64_t _ZN7MMCodec10MTResample8resampleEPPhiS2_Pii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x168c28
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x168c3c
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x168c48
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6ffd6 = "[%s(%d)]:> input parameters invalid"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168cf0
    const char* s_81542 = "%s/MTMV_AICodec: [%s(%d)]:> input parameters invalid
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168d2c
    return a0;
    _ZN7MMCodec14FFmpegResample8resampleEP7AVFramePPhPii(...); // call imported API via PLT at 0x168d6c
    const char* s_79b56 = "resample"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_76e21 = "[%s(%d)]:> [%s] resample failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168dbc
    const char* s_79b56 = "resample"; // string xref
    const char* s_7c172 = "%s/MTMV_AICodec: [%s(%d)]:> [%s] resample failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168e04
    return a0;
}
