// Library: libaicodec.so
// Function ID: libaicodec::0x107198
// Recovered Name: sub_107198
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107198 | Size: 196 bytes | SHA256: c547cffcb9d5e5ffaba2206b919cddcce3864bdb92938dbd88242da4f2284c19
// Callers: 0 | Callees: 0 | Imports: 5

// Dynamic Registration: native_close(J)V (table at 0x1fec48)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MTMediaReader5closeEv, _ZN7MMCodec13MTMediaReaderD1Ev, _ZdlPv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_close"

jlong sub_107198(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x107198 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x10719c */ str x19, [sp, #0x10];
    /* 0x1071a0 */ mov x29, sp;
    /* 0x1071a4 */ cbz x2, #0x1071cc;
    /* 0x1071a8 */ mov x0, x2;
    /* 0x1071ac */ mov x19, x2;
    _ZN7MMCodec13MTMediaReader5closeEv();
    /* 0x1071b4 */ mov x0, x19;
    _ZN7MMCodec13MTMediaReaderD1Ev();
    /* 0x1071bc */ mov x0, x19;
    /* 0x1071c0 */ ldr x19, [sp, #0x10];
    __android_log_print();
    return x0;
}
