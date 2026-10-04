// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12610c
// Recovered Name: sub_12610c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12610c | Size: 200 bytes | SHA256: 5bc2cefbc11b15727a5c5f0fe602f9a2316cf2e05fcbeec197ba096baeb8089c
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_checkIsSRGB(J)Z (table at 0x13aad8)
// Calls external APIs: _ZN3PVG17PVGImageTranscode11checkIsSRGBEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGImageTranscode_native_checkIsSRGB"
//   "PVGCodec"

jlong sub_12610c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x12610c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x126110 */ mov x29, sp;
    /* 0x126114 */ cbz x2, #0x12612c;
    /* 0x126118 */ mov x0, x2;
    _ZN3PVG17PVGImageTranscode11checkIsSRGBEv();
    /* 0x126120 */ and w0, w0, #1;
    /* 0x126124 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x12612c */ adrp x8, #0x13b000;
    /* 0x126130 */ ldr x8, [x8, #0x198];
    /* 0x126134 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
