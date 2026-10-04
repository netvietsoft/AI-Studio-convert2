// Library: libaicodec.so
// Function ID: libaicodec::0x107960
// Recovered Name: sub_107960
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107960 | Size: 168 bytes | SHA256: 745dab67005483aebeac4fbf532803b2a89e6dbd9f1c635984c3792b918247b6
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getVideoBitrate(J)J (table at 0x1fed50)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getVideoBitrate"

jlong sub_107960(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x107960 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107964 */ mov x29, sp;
    /* 0x107968 */ cbz x2, #0x107980;
    /* 0x10796c */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107974 */ ldr x0, [x0, #0xb8];
    /* 0x107978 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x107980 */ adrp x8, #0x201000;
    /* 0x107984 */ ldr x8, [x8, #0x868];
    /* 0x107988 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
