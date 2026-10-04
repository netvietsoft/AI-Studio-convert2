// Function: MMCodec::MTResample::resample(unsigned char*, unsigned long, unsigned char*, unsigned long&, int)
// RVA: 0x168770, Size: 376 bytes
int64_t _ZN7MMCodec10MTResample8resampleEPhmS1_Rmi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1687c8
    av_samples_fill_arrays(...); // call imported API via PLT at 0x1687e8
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1687f4
    _ZN7MMCodec10MTResample8resampleEPPhiS1_Rmi(...); // call imported API via PLT at 0x16881c
    return a0;
    const char* s_79b56 = "resample"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_894e3 = "[%s(%d)]:> [%s] inData av_samples_fill_arrays failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16888c
    const char* s_79b56 = "resample"; // string xref
    const char* s_7359b = "%s/MTMV_AICodec: [%s(%d)]:> [%s] inData av_samples_fill_arrays failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1688cc
    __stack_chk_fail(...); // call imported API via PLT at 0x1688e4
}
