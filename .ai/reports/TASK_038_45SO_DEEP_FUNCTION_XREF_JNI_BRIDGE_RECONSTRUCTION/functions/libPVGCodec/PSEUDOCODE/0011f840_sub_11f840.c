// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11f840
// Recovered Name: sub_11f840
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11f840 | Size: 204 bytes | SHA256: c80f31713416311637662ae437b2ead4d396e2a20929642832c4d6a32ada5706
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a628)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaConcat_native_finalize"
//   "PVGCodec"

jlong sub_11f840(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x11f840 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11f844 */ mov x29, sp;
    /* 0x11f848 */ cbz x2, #0x11f868;
    /* 0x11f84c */ ldr x8, [x2];
    /* 0x11f850 */ mov x0, x2;
    /* 0x11f854 */ ldr x8, [x8, #8];
    /* 0x11f858 */ blr x8;
    /* 0x11f85c */ mov w0, wzr;
    /* 0x11f860 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x11f868 */ adrp x8, #0x13b000;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
