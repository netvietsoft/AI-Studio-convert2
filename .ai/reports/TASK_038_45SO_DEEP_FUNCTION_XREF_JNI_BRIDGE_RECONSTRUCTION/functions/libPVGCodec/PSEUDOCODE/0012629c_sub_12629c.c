// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12629c
// Recovered Name: sub_12629c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12629c | Size: 200 bytes | SHA256: 30a4fe20b2f7008c4f5725aaca8c90b823bde5221625adc776f4d19d2b8f6023
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_checkHasAlpha(J)Z (table at 0x13ab08)
// Calls external APIs: _ZN3PVG17PVGImageTranscode13checkHasAlphaEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGImageTranscode_native_checkHasAlpha"
//   "PVGCodec"

jlong sub_12629c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x12629c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1262a0 */ mov x29, sp;
    /* 0x1262a4 */ cbz x2, #0x1262bc;
    /* 0x1262a8 */ mov x0, x2;
    _ZN3PVG17PVGImageTranscode13checkHasAlphaEv();
    /* 0x1262b0 */ and w0, w0, #1;
    /* 0x1262b4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1262bc */ adrp x8, #0x13b000;
    /* 0x1262c0 */ ldr x8, [x8, #0x198];
    /* 0x1262c4 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
