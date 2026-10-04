// Library: libaicodec.so
// Function ID: libaicodec::0x107c40
// Recovered Name: sub_107c40
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107c40 | Size: 168 bytes | SHA256: 4cdac8ff49f002898feefdeed96236d6f061a7e5aeb7304277a3bc009f2f1187
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getAudioSampleRate(J)J (table at 0x1fedb0)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getAudioSampleRate"

jlong sub_107c40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107c40 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107c44 */ mov x29, sp;
    /* 0x107c48 */ cbz x2, #0x107c60;
    /* 0x107c4c */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107c54 */ ldrsw x0, [x0, #0x1f4];
    /* 0x107c58 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107c60 */ adrp x8, #0x201000;
    /* 0x107c64 */ ldr x8, [x8, #0x868];
    /* 0x107c68 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
