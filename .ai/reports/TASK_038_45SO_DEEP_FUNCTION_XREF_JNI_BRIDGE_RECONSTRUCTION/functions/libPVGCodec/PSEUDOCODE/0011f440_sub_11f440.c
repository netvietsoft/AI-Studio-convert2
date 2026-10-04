// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11f440
// Recovered Name: sub_11f440
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11f440 | Size: 196 bytes | SHA256: 487829acec4829b9386b68889f1bae1080f3b534f1f697ee32b3c2a6c3041966
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getOutDuration(J)D (table at 0x13a5c8)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaCombiner_native_getOutDuration"
//   "PVGCodec"

jlong sub_11f440(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x11f440 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11f444 */ mov x29, sp;
    /* 0x11f448 */ cbz x2, #0x11f45c;
    /* 0x11f44c */ ldr d0, [x2, #0x50];
    /* 0x11f450 */ scvtf d0, d0;
    /* 0x11f454 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x11f45c */ adrp x8, #0x13b000;
    /* 0x11f460 */ ldr x8, [x8, #0x198];
    /* 0x11f464 */ ldr w8, [x8];
    /* 0x11f468 */ cmp w8, #5;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
