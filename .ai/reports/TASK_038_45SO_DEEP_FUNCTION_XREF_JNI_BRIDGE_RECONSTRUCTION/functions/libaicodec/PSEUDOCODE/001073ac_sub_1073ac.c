// Library: libaicodec.so
// Function ID: libaicodec::0x1073ac
// Recovered Name: sub_1073ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1073ac | Size: 176 bytes | SHA256: ec25bb1208b2d74e02c6e94510c98c70156c6ee8727dec89a1f72afa7250326e
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getDuration(J)D (table at 0x1fec90)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getDuration"

jlong sub_1073ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x1073ac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1073b0 */ mov x29, sp;
    /* 0x1073b4 */ cbz x2, #0x1073c8;
    /* 0x1073b8 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x1073c0 */ ldr d0, [x0];
    /* 0x1073c4 */ b #0x107454;
    /* 0x1073c8 */ adrp x8, #0x201000;
    /* 0x1073cc */ ldr x8, [x8, #0x868];
    /* 0x1073d0 */ ldr w8, [x8];
    /* 0x1073d4 */ cmp w8, #5;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    return x0;
}
