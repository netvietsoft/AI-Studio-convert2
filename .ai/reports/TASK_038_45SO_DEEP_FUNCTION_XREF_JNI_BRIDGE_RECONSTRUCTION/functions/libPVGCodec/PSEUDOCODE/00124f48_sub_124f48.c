// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x124f48
// Recovered Name: sub_124f48
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x124f48 | Size: 200 bytes | SHA256: c20cae906986a5d63464acc019c06026e257ccf7ace200d6758d59aed0fa6d34
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_abort(J)I (table at 0x13aa18)
// Calls external APIs: _ZN3PVG18PVGFormatTranscode5abortEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGFormatTranscode_native_abort"
//   "PVGCodec"

jlong sub_124f48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x124f48 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x124f4c */ mov x29, sp;
    /* 0x124f50 */ cbz x2, #0x124f68;
    /* 0x124f54 */ mov x0, x2;
    _ZN3PVG18PVGFormatTranscode5abortEv();
    /* 0x124f5c */ mov w0, wzr;
    /* 0x124f60 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x124f68 */ adrp x8, #0x13b000;
    /* 0x124f6c */ ldr x8, [x8, #0x198];
    /* 0x124f70 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
