// Function: MMCodec::copyAudioArray(AVSampleFormat, int, unsigned char**, unsigned char**, int*, int)
// RVA: 0x1670a0, Size: 212 bytes
int64_t _ZN7MMCodec14copyAudioArrayE14AVSampleFormatiPPhS2_Pii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1670cc
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x1670d8
    memmove(...); // call imported API via PLT at 0x167100
    return a0;
    memmove(...); // call imported API via PLT at 0x167140
    return a0;
    return a0;
}
