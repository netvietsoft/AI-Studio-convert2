// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x123f40
// Recovered Name: sub_123f40
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x123f40 | Size: 228 bytes | SHA256: 1fcc60ba30ec081f0793e6dab725612374155e2f1769cd998aa07454731af7d2
// Callers: 0 | Callees: 0 | Imports: 6

// Dynamic Registration: native_finalize(J)I (table at 0x13a988)
// Calls external APIs: _ZN3PVG18PVGFormatTranscode5closeEv, _ZN3PVG18PVGFormatTranscodeD1Ev, _ZN3PVG19logCallbackInternalEiPKcz, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGFormatTranscode_native_finalize"
//   "PVGCodec"

jlong sub_123f40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x123f40 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x123f44 */ str x19, [sp, #0x10];
    /* 0x123f48 */ mov x29, sp;
    /* 0x123f4c */ cbz x2, #0x123f7c;
    /* 0x123f50 */ mov x0, x2;
    /* 0x123f54 */ mov x19, x2;
    _ZN3PVG18PVGFormatTranscode5closeEv();
    /* 0x123f5c */ mov x0, x19;
    _ZN3PVG18PVGFormatTranscodeD1Ev();
    /* 0x123f64 */ mov x0, x19;
    _ZdlPv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
