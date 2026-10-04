// Library: libaicodec.so
// Function ID: libaicodec::0x107b98
// Recovered Name: sub_107b98
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107b98 | Size: 168 bytes | SHA256: ab527466d20107342a0a566c8ec3a4653dad5b90c8d380d2cefaafb9addba25b
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getAudioBitrate(J)J (table at 0x1fed98)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getAudioBitrate"

jlong sub_107b98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107b98 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107b9c */ mov x29, sp;
    /* 0x107ba0 */ cbz x2, #0x107bb8;
    /* 0x107ba4 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107bac */ ldr x0, [x0, #0x200];
    /* 0x107bb0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107bb8 */ adrp x8, #0x201000;
    /* 0x107bbc */ ldr x8, [x8, #0x868];
    /* 0x107bc0 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
