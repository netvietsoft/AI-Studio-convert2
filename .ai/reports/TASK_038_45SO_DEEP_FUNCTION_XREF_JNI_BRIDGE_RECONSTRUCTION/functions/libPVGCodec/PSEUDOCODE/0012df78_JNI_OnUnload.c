// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12df78
// Recovered Name: JNI_OnUnload
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x12df78 | Size: 180 bytes | SHA256: 97109c01fb1a48cb59fd0da6098588d597406e0203bcff470432c605db5696fd
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> %s"
//   "F[%s, L(%d)], T(%p):> %s"
//   "JNI_OnUnload"

jlong JNI_OnUnload(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x12df78 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x12df7c */ mov x29, sp;
    /* 0x12df80 */ adrp x8, #0x13b000;
    /* 0x12df84 */ ldr x8, [x8, #0x198];
    /* 0x12df88 */ ldr w8, [x8];
    /* 0x12df8c */ cmp w8, #3;
    /* 0x12df90 */ b.gt #0x12dfc4;
    pthread_self();
    /* 0x12df98 */ adrp x3, #0x33000;
    /* 0x12df9c */ add x3, x3, #0x5ed;
    /* 0x12dfa0 */ mov x5, x0;
    __android_log_print();
    pthread_self();
    return x0;
}
