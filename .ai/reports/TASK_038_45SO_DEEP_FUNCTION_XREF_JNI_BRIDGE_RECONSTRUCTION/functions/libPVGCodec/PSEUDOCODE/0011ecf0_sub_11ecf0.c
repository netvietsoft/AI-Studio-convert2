// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11ecf0
// Recovered Name: sub_11ecf0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11ecf0 | Size: 228 bytes | SHA256: 3e734054f84f14d3b807ec203389b1eeda27ab1762adf914d2456623199673f0
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_finalize(J)I (table at 0x13a598)
// Calls external APIs: _ZN3PVG13MediaCombiner7releaseEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaCombiner_native_finalize"
//   "PVGCodec"

jlong sub_11ecf0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x11ecf0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11ecf4 */ str x19, [sp, #0x10];
    /* 0x11ecf8 */ mov x29, sp;
    /* 0x11ecfc */ cbz x2, #0x11ed2c;
    /* 0x11ed00 */ mov x0, x2;
    /* 0x11ed04 */ mov x19, x2;
    _ZN3PVG13MediaCombiner7releaseEv();
    /* 0x11ed0c */ ldr x8, [x19];
    /* 0x11ed10 */ mov x0, x19;
    /* 0x11ed14 */ ldr x8, [x8, #8];
    /* 0x11ed18 */ blr x8;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
