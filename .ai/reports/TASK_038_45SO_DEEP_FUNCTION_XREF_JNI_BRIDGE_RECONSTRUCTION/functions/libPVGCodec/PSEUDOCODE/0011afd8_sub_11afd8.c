// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11afd8
// Recovered Name: sub_11afd8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11afd8 | Size: 236 bytes | SHA256: 78c4f0ef8300a49b5b26ee299e43173b173e4b3df7f949acd22980a99e0ab42f
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a1b0)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIExtractVideoClip_native_finalize"
//   "PVGCodec"

jlong sub_11afd8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x11afd8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11afdc */ str x19, [sp, #0x10];
    /* 0x11afe0 */ mov x29, sp;
    /* 0x11afe4 */ cbz x2, #0x11b01c;
    /* 0x11afe8 */ ldr x8, [x2];
    /* 0x11afec */ mov x0, x2;
    /* 0x11aff0 */ mov x19, x2;
    /* 0x11aff4 */ ldr x8, [x8, #0x18];
    /* 0x11aff8 */ blr x8;
    /* 0x11affc */ ldr x8, [x19];
    /* 0x11b000 */ mov x0, x19;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
