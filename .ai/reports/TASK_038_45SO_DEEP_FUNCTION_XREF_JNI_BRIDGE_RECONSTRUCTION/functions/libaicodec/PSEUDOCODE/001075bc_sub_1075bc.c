// Library: libaicodec.so
// Function ID: libaicodec::0x1075bc
// Recovered Name: sub_1075bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1075bc | Size: 168 bytes | SHA256: 9fa0f63518879093c808491fdc56fcac4753a6ea7e67685f8d5047d8b8f26676
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getVideoWidth(J)I (table at 0x1fecd8)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getVideoWidth"

jlong sub_1075bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x1075bc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1075c0 */ mov x29, sp;
    /* 0x1075c4 */ cbz x2, #0x1075dc;
    /* 0x1075c8 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x1075d0 */ ldr w0, [x0, #0xa0];
    /* 0x1075d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1075dc */ adrp x8, #0x201000;
    /* 0x1075e0 */ ldr x8, [x8, #0x868];
    /* 0x1075e4 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
