// Function: MMCodec::MTResample::resample(unsigned char**, int, unsigned char*, unsigned long&, int)
// RVA: 0x1688e8, Size: 772 bytes
int64_t _ZN7MMCodec10MTResample8resampleEPPhiS1_Rmi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x168948
    _ZN7MMCodec14FFmpegResample17getNextOutSamplesEii(...); // call imported API via PLT at 0x168968
    av_samples_fill_arrays(...); // call imported API via PLT at 0x168988
    _ZN7MMCodec10MTResample8resampleEPPhiS2_Pii(...); // call imported API via PLT at 0x1689a8
    _ZN7MMCodec14copyAudioArrayE14AVSampleFormatiPPhS1_Rmi(...); // call imported API via PLT at 0x1689d0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6c710 = "[%s(%d)]:> copy audio failed"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168a1c
    const char* s_83c3d = "%s/MTMV_AICodec: [%s(%d)]:> copy audio failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _Znwm(...); // call imported API via PLT at 0x168a5c
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0x168a68
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x168a78
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c155 = "[%s(%d)]:> malloc buf failed"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168abc
    const char* s_6a5c0 = "%s/MTMV_AICodec: [%s(%d)]:> malloc buf failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168af8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_735e2 = "[%s(%d)]:> fill array failed"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168b50
    const char* s_87bff = "%s/MTMV_AICodec: [%s(%d)]:> fill array failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168b8c
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x168bcc
    __stack_chk_fail(...); // call imported API via PLT at 0x168be8
}
