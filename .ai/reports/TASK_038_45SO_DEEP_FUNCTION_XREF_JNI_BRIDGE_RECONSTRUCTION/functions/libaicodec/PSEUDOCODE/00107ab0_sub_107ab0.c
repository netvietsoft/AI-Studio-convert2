// Library: libaicodec.so
// Function ID: libaicodec::0x107ab0
// Recovered Name: sub_107ab0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107ab0 | Size: 232 bytes | SHA256: cc1c2534d754cedbe47a4fe251a1e3f5ab5839bd18060e7a428852ef96ff597e
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getAudioCodec(J)Ljava/lang/String; (table at 0x1fed80)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getAudioCodec"

jlong sub_107ab0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x107ab0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x107ab4 */ str x19, [sp, #0x10];
    /* 0x107ab8 */ mov x29, sp;
    /* 0x107abc */ cbz x2, #0x107ae8;
    /* 0x107ac0 */ mov x19, x0;
    /* 0x107ac4 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107acc */ ldr x8, [x19];
    /* 0x107ad0 */ add x1, x0, #0x208;
    /* 0x107ad4 */ ldr x2, [x8, #0x538];
    /* 0x107ad8 */ mov x0, x19;
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
