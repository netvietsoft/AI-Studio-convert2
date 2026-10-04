// Function: MMCodec::copyAudioArray(AVSampleFormat, int, unsigned char**, unsigned char*, unsigned long&, int)
// RVA: 0x167174, Size: 220 bytes
int64_t _ZN7MMCodec14copyAudioArrayE14AVSampleFormatiPPhS1_Rmi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1671a0
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x1671b8
    memmove(...); // call imported API via PLT at 0x1671e0
    return a0;
    memmove(...); // call imported API via PLT at 0x16721c
    return a0;
    return a0;
}
