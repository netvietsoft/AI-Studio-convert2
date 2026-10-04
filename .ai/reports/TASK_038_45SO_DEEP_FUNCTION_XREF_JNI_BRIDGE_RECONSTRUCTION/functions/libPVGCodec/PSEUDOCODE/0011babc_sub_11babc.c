// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11babc
// Recovered Name: sub_11babc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11babc | Size: 196 bytes | SHA256: c1b8bd6ccf1c2ab7ec876d16e21ffe48a31e4a0a240fd388f60fb1abe93e58f3
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_abort(J)V (table at 0x13a228)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIExtractVideoClip_native_abort"
//   "PVGCodec"

jlong sub_11babc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x11babc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11bac0 */ mov x29, sp;
    /* 0x11bac4 */ cbz x2, #0x11badc;
    /* 0x11bac8 */ ldr x8, [x2];
    /* 0x11bacc */ ldr x1, [x8, #0x28];
    /* 0x11bad0 */ mov x0, x2;
    /* 0x11bad4 */ ldp x29, x30, [sp], #0x10;
    /* 0x11bad8 */ br x1;
    /* 0x11badc */ adrp x8, #0x13b000;
    /* 0x11bae0 */ ldr x8, [x8, #0x198];
    /* 0x11bae4 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    return x0;
}
