// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1298cc
// Recovered Name: sub_1298cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1298cc | Size: 220 bytes | SHA256: fa69392986d4f1f7cc3bf3ccab9d0f1514c4859fecc3425f929a38c5b1c4e8ef
// Callers: 0 | Callees: 0 | Imports: 5

// Dynamic Registration: native_finalize(J)I (table at 0x13aca0)
// Calls external APIs: _ZN3PVG12PVGWaterMarkD1Ev, _ZN3PVG19logCallbackInternalEiPKcz, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGWaterMark_native_finalize"
//   "PVGCodec"

jlong sub_1298cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x1298cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1298d0 */ str x19, [sp, #0x10];
    /* 0x1298d4 */ mov x29, sp;
    /* 0x1298d8 */ cbz x2, #0x129900;
    /* 0x1298dc */ mov x0, x2;
    /* 0x1298e0 */ mov x19, x2;
    _ZN3PVG12PVGWaterMarkD1Ev();
    /* 0x1298e8 */ mov x0, x19;
    _ZdlPv();
    /* 0x1298f0 */ mov w0, wzr;
    /* 0x1298f4 */ ldr x19, [sp, #0x10];
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
