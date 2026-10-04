// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x119784
// Recovered Name: sub_119784
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x119784 | Size: 204 bytes | SHA256: 831cc35ae018d004c61cfc7ce3ebab8b76bca1441624899556c1a128db312837
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a0c0)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIAudioExtractor_native_finalize"
//   "PVGCodec"

jlong sub_119784(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x119784 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x119788 */ mov x29, sp;
    /* 0x11978c */ cbz x2, #0x1197ac;
    /* 0x119790 */ ldr x8, [x2];
    /* 0x119794 */ mov x0, x2;
    /* 0x119798 */ ldr x8, [x8, #8];
    /* 0x11979c */ blr x8;
    /* 0x1197a0 */ mov w0, wzr;
    /* 0x1197a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1197ac */ adrp x8, #0x13b000;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
