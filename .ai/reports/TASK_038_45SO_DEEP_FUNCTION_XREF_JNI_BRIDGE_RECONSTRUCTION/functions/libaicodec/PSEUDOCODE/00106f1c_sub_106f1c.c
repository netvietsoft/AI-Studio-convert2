// Library: libaicodec.so
// Function ID: libaicodec::0x106f1c
// Recovered Name: sub_106f1c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x106f1c | Size: 180 bytes | SHA256: 64cba7e6f15bdd63a77448c85487bbe10d76f9ab65e9ba21d787ec027e695a65
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_start(J)Z (table at 0x1febe8)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_start"

jlong sub_106f1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x106f1c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x106f20 */ mov x29, sp;
    /* 0x106f24 */ cbz x2, #0x106f48;
    /* 0x106f28 */ mov x0, x2;
    /* 0x106f2c */ mov x1, xzr;
    /* 0x106f30 */ mov x2, xzr;
    /* 0x106f34 */ mov x3, xzr;
    _ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll();
    /* 0x106f3c */ mov w0, #1;
    /* 0x106f40 */ ldp x29, x30, [sp], #0x10;
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
