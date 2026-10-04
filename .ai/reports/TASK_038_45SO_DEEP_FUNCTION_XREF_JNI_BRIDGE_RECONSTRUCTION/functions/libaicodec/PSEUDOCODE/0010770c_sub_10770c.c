// Library: libaicodec.so
// Function ID: libaicodec::0x10770c
// Recovered Name: sub_10770c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x10770c | Size: 176 bytes | SHA256: 679690fe301b47da2d53a28a336fa2ea67d9ac88be328e744cbf97811b74ac0d
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getFps(J)F (table at 0x1fed08)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getFps"

jlong sub_10770c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x10770c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107710 */ mov x29, sp;
    /* 0x107714 */ cbz x2, #0x107728;
    /* 0x107718 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107720 */ ldr s0, [x0, #0x98];
    /* 0x107724 */ b #0x1077b4;
    /* 0x107728 */ adrp x8, #0x201000;
    /* 0x10772c */ ldr x8, [x8, #0x868];
    /* 0x107730 */ ldr w8, [x8];
    /* 0x107734 */ cmp w8, #5;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    return x0;
}
