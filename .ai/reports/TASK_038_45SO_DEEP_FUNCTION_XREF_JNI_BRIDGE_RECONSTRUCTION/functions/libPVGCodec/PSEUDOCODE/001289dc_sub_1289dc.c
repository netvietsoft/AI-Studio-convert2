// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1289dc
// Recovered Name: sub_1289dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1289dc | Size: 196 bytes | SHA256: 03ad0552e504737c1b88c07af6264ea9658ec7a8bfb96215557319a14b2fc9ba
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_finalize(J)I (table at 0x13abf8)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGVideoToImage_native_finalize"
//   "PVGCodec"

jlong sub_1289dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x1289dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1289e0 */ mov x29, sp;
    /* 0x1289e4 */ cbz x2, #0x1289fc;
    /* 0x1289e8 */ mov x0, x2;
    _ZN3PVG6PVGRef7releaseEv();
    /* 0x1289f0 */ mov w0, wzr;
    /* 0x1289f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1289fc */ adrp x8, #0x13b000;
    /* 0x128a00 */ ldr x8, [x8, #0x198];
    /* 0x128a04 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
