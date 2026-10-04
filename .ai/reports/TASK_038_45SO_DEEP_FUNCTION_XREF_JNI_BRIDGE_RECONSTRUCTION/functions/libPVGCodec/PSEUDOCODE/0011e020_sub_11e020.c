// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11e020
// Recovered Name: sub_11e020
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11e020 | Size: 228 bytes | SHA256: 6fe46cf5078b141b8c04dd5e5fead38799c44c65a3b06d5b10b88ad9c19a5e07
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_finalize(J)I (table at 0x13a4f0)
// Calls external APIs: _ZN3PVG12MediaClipper7releaseEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaClipper_native_finalize"
//   "PVGCodec"

jlong sub_11e020(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x11e020 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11e024 */ str x19, [sp, #0x10];
    /* 0x11e028 */ mov x29, sp;
    /* 0x11e02c */ cbz x2, #0x11e05c;
    /* 0x11e030 */ mov x0, x2;
    /* 0x11e034 */ mov x19, x2;
    _ZN3PVG12MediaClipper7releaseEv();
    /* 0x11e03c */ ldr x8, [x19];
    /* 0x11e040 */ mov x0, x19;
    /* 0x11e044 */ ldr x8, [x8, #8];
    /* 0x11e048 */ blr x8;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
