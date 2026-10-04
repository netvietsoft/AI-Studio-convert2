// Library: libaicodec.so
// Function ID: libaicodec::0x107a08
// Recovered Name: sub_107a08
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107a08 | Size: 168 bytes | SHA256: 75bbdc4b0db7e10237d55d7c8840e9214b8aa829f14f6db759d781c29b59ebef
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getFramesNumber(J)I (table at 0x1fed68)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getFramesNumber"

jlong sub_107a08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107a08 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107a0c */ mov x29, sp;
    /* 0x107a10 */ cbz x2, #0x107a28;
    /* 0x107a14 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107a1c */ ldr w0, [x0, #0xb4];
    /* 0x107a20 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107a28 */ adrp x8, #0x201000;
    /* 0x107a2c */ ldr x8, [x8, #0x868];
    /* 0x107a30 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
