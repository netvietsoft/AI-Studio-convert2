// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11a2a4
// Recovered Name: sub_11a2a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11a2a4 | Size: 200 bytes | SHA256: df84477c7078be776fc5920072bcf39b5de7bb9e3e9a99e341c429d83e7bd547
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_abort(J)I (table at 0x13a120)
// Calls external APIs: _ZN3PVG17PVGAudioExtractor5abortEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIAudioExtractor_native_abort"
//   "PVGCodec"

jlong sub_11a2a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x11a2a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11a2a8 */ mov x29, sp;
    /* 0x11a2ac */ cbz x2, #0x11a2c4;
    /* 0x11a2b0 */ mov x0, x2;
    _ZN3PVG17PVGAudioExtractor5abortEv();
    /* 0x11a2b8 */ mov w0, wzr;
    /* 0x11a2bc */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x11a2c4 */ adrp x8, #0x13b000;
    /* 0x11a2c8 */ ldr x8, [x8, #0x198];
    /* 0x11a2cc */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
