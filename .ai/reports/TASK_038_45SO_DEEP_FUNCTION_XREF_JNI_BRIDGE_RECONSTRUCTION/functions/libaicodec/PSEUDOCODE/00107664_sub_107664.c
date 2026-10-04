// Library: libaicodec.so
// Function ID: libaicodec::0x107664
// Recovered Name: sub_107664
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107664 | Size: 168 bytes | SHA256: ee0c2d7a1550bd904c4d07be7da8fe160e7b47ecfec3aa0239fc9a0afba3c74f
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getVideoHeight(J)I (table at 0x1fecf0)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getVideoHeight"

jlong sub_107664(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107664 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107668 */ mov x29, sp;
    /* 0x10766c */ cbz x2, #0x107684;
    /* 0x107670 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107678 */ ldr w0, [x0, #0xa4];
    /* 0x10767c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107684 */ adrp x8, #0x201000;
    /* 0x107688 */ ldr x8, [x8, #0x868];
    /* 0x10768c */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
