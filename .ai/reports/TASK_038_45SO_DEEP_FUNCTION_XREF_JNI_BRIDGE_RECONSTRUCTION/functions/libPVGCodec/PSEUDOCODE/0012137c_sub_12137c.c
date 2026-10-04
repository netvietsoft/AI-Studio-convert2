// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12137c
// Recovered Name: sub_12137c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12137c | Size: 204 bytes | SHA256: 9dd9cb32e486eb7c15e94a7cecec6b2ef2d665bd5f653e8008866d7fcf1f692a
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a7f0)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaReverser_native_finalize"
//   "PVGCodec"

jlong sub_12137c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x12137c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x121380 */ mov x29, sp;
    /* 0x121384 */ cbz x2, #0x1213a4;
    /* 0x121388 */ ldr x8, [x2];
    /* 0x12138c */ mov x0, x2;
    /* 0x121390 */ ldr x8, [x8, #8];
    /* 0x121394 */ blr x8;
    /* 0x121398 */ mov w0, wzr;
    /* 0x12139c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1213a4 */ adrp x8, #0x13b000;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
