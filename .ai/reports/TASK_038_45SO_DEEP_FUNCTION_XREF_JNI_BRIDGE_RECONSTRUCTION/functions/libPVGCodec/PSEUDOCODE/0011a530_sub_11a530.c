// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11a530
// Recovered Name: sub_11a530
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11a530 | Size: 220 bytes | SHA256: 2f18d3e768240cd223cb53bccb25e5aaee11fe20ca326ed4b565dcf0cf06d4ae
// Callers: 0 | Callees: 0 | Imports: 5

// Dynamic Registration: native_finalize(J)I (table at 0x13a150)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG22PVGAudioNoiseReductionD1Ev, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIAudioNoiseReduction_native_finalize"
//   "PVGCodec"

jlong sub_11a530(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x11a530 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11a534 */ str x19, [sp, #0x10];
    /* 0x11a538 */ mov x29, sp;
    /* 0x11a53c */ cbz x2, #0x11a564;
    /* 0x11a540 */ mov x0, x2;
    /* 0x11a544 */ mov x19, x2;
    _ZN3PVG22PVGAudioNoiseReductionD1Ev();
    /* 0x11a54c */ mov x0, x19;
    _ZdlPv();
    /* 0x11a554 */ mov w0, wzr;
    /* 0x11a558 */ ldr x19, [sp, #0x10];
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
