// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x118d18
// Recovered Name: sub_118d18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118d18 | Size: 228 bytes | SHA256: c30b556d34e202a2b912445edf5df6cdaf9f3dd8772913f5fde69056c0d3b430
// Callers: 0 | Callees: 0 | Imports: 6

// Dynamic Registration: native_finalize(J)I (table at 0x13a000)
// Calls external APIs: _ZN3PVG15PVGAudioDecoder5closeEv, _ZN3PVG15PVGAudioDecoderD1Ev, _ZN3PVG19logCallbackInternalEiPKcz, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIAudioDecoder_native_finalize"
//   "PVGCodec"

jlong sub_118d18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x118d18 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x118d1c */ str x19, [sp, #0x10];
    /* 0x118d20 */ mov x29, sp;
    /* 0x118d24 */ cbz x2, #0x118d54;
    /* 0x118d28 */ mov x0, x2;
    /* 0x118d2c */ mov x19, x2;
    _ZN3PVG15PVGAudioDecoder5closeEv();
    /* 0x118d34 */ mov x0, x19;
    _ZN3PVG15PVGAudioDecoderD1Ev();
    /* 0x118d3c */ mov x0, x19;
    _ZdlPv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
