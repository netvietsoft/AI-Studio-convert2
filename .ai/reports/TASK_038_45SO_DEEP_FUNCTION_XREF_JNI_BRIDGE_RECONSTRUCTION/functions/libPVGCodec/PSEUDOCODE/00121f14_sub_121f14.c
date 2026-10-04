// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x121f14
// Recovered Name: sub_121f14
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x121f14 | Size: 196 bytes | SHA256: ff0beb43c7966ca1066c7b5f5530b7ac6fc2c68ba4705e6dfc02404539e35de1
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_finalize(J)I (table at 0x13a880)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGCodec_native_finalize"
//   "PVGCodec"

jlong sub_121f14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x121f14 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x121f18 */ mov x29, sp;
    /* 0x121f1c */ cbz x2, #0x121f34;
    /* 0x121f20 */ mov x0, x2;
    _ZN3PVG6PVGRef7releaseEv();
    /* 0x121f28 */ mov w0, wzr;
    /* 0x121f2c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x121f34 */ adrp x8, #0x13b000;
    /* 0x121f38 */ ldr x8, [x8, #0x198];
    /* 0x121f3c */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
