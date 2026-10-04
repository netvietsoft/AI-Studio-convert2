// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1261d4
// Recovered Name: sub_1261d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1261d4 | Size: 200 bytes | SHA256: 9618e68e57a8deccda776922fef3ed469f078fa98befc6ecbf6f0aa847f83618
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_checkIsHDR(J)Z (table at 0x13aaf0)
// Calls external APIs: _ZN3PVG17PVGImageTranscode10checkIsHDREv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGImageTranscode_native_checkIsHDR"
//   "PVGCodec"

jlong sub_1261d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x1261d4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1261d8 */ mov x29, sp;
    /* 0x1261dc */ cbz x2, #0x1261f4;
    /* 0x1261e0 */ mov x0, x2;
    _ZN3PVG17PVGImageTranscode10checkIsHDREv();
    /* 0x1261e8 */ and w0, w0, #1;
    /* 0x1261ec */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1261f4 */ adrp x8, #0x13b000;
    /* 0x1261f8 */ ldr x8, [x8, #0x198];
    /* 0x1261fc */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
