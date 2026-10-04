// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x123cd0
// Recovered Name: sub_123cd0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x123cd0 | Size: 200 bytes | SHA256: ae8efe2a092adffc041e5002663237c4866fc7eadfd222c9fa23b1c6c7e3e0fa
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_abort(J)I (table at 0x13a958)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG8PVGCodec5abortEv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGCodec_native_abort"
//   "PVGCodec"

jlong sub_123cd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x123cd0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x123cd4 */ mov x29, sp;
    /* 0x123cd8 */ cbz x2, #0x123cf0;
    /* 0x123cdc */ mov x0, x2;
    _ZN3PVG8PVGCodec5abortEv();
    /* 0x123ce4 */ mov w0, wzr;
    /* 0x123ce8 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x123cf0 */ adrp x8, #0x13b000;
    /* 0x123cf4 */ ldr x8, [x8, #0x198];
    /* 0x123cf8 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
