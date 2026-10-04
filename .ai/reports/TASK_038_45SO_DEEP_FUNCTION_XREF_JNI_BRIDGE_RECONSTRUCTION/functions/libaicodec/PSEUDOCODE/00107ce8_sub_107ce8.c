// Library: libaicodec.so
// Function ID: libaicodec::0x107ce8
// Recovered Name: sub_107ce8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107ce8 | Size: 180 bytes | SHA256: 34b300cef5122aecb7279c5ee8b7412649e3c59faf42b97706eeb5395bcd82e8
// Callers: 0 | Callees: 0 | Imports: 5

// Dynamic Registration: native_getSizePerSample(J)J (table at 0x1fedc8)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, av_get_bytes_per_sample
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getSizePerSample"

jlong sub_107ce8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x107ce8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107cec */ mov x29, sp;
    /* 0x107cf0 */ cbz x2, #0x107d14;
    /* 0x107cf4 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107cfc */ ldr w0, [x0, #0x1f8];
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE();
    av_get_bytes_per_sample();
    /* 0x107d08 */ sxtw x0, w0;
    /* 0x107d0c */ ldp x29, x30, [sp], #0x10;
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
