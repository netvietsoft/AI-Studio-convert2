// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12a87c
// Recovered Name: sub_12a87c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12a87c | Size: 200 bytes | SHA256: 04dfb3f17b2929f2a799cded2fa09027af832f690d66ac7a0e15925b8b69dbf0
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_abort(J)I (table at 0x13ad30)
// Calls external APIs: _ZN3PVG12PVGWaterMark5abortEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGWaterMark_native_abort"
//   "PVGCodec"

jlong sub_12a87c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x12a87c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x12a880 */ mov x29, sp;
    /* 0x12a884 */ cbz x2, #0x12a89c;
    /* 0x12a888 */ mov x0, x2;
    _ZN3PVG12PVGWaterMark5abortEv();
    /* 0x12a890 */ mov w0, wzr;
    /* 0x12a894 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x12a89c */ adrp x8, #0x13b000;
    /* 0x12a8a0 */ ldr x8, [x8, #0x198];
    /* 0x12a8a4 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
