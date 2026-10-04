// Library: libaicodec.so
// Function ID: libaicodec::0x107304
// Recovered Name: sub_107304
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107304 | Size: 168 bytes | SHA256: 3c007e83f7c85f240f2bd0d1ae01e305f44bcec4a15977917a4518b63386ce5a
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_hasVideo(J)Z (table at 0x1fec78)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_hasVideo"

jlong sub_107304(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107304 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107308 */ mov x29, sp;
    /* 0x10730c */ cbz x2, #0x107324;
    /* 0x107310 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107318 */ ldrb w0, [x0, #0x8c];
    /* 0x10731c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107324 */ adrp x8, #0x201000;
    /* 0x107328 */ ldr x8, [x8, #0x868];
    /* 0x10732c */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
