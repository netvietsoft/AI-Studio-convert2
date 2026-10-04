// Library: libaicodec.so
// Function ID: libaicodec::0x10745c
// Recovered Name: sub_10745c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x10745c | Size: 176 bytes | SHA256: 951fe72b3b018f776aeb2840511608888a4cea3be68bf38c59b93667ec43e5c1
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getVideoDuration(J)D (table at 0x1feca8)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getVideoDuration"

jlong sub_10745c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x10745c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107460 */ mov x29, sp;
    /* 0x107464 */ cbz x2, #0x107478;
    /* 0x107468 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107470 */ ldr d0, [x0, #0x90];
    /* 0x107474 */ b #0x107504;
    /* 0x107478 */ adrp x8, #0x201000;
    /* 0x10747c */ ldr x8, [x8, #0x868];
    /* 0x107480 */ ldr w8, [x8];
    /* 0x107484 */ cmp w8, #5;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    return x0;
}
