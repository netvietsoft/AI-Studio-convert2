// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11bd98
// Recovered Name: sub_11bd98
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11bd98 | Size: 204 bytes | SHA256: 81916fefe84ecdc47d5999dc3249d5e73d9bfd3984f243c246643757c5f0bc57
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a2a8)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIGifMetaData_native_finalize"
//   "PVGCodec"

jlong sub_11bd98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x11bd98 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11bd9c */ mov x29, sp;
    /* 0x11bda0 */ cbz x2, #0x11bdc0;
    /* 0x11bda4 */ ldr x8, [x2];
    /* 0x11bda8 */ mov x0, x2;
    /* 0x11bdac */ ldr x8, [x8, #8];
    /* 0x11bdb0 */ blr x8;
    /* 0x11bdb4 */ mov w0, wzr;
    /* 0x11bdb8 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x11bdc0 */ adrp x8, #0x13b000;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
