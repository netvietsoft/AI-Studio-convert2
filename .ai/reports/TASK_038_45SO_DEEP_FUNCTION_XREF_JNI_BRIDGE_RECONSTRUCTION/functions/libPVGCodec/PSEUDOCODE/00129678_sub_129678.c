// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x129678
// Recovered Name: sub_129678
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x129678 | Size: 200 bytes | SHA256: 2879bb8d5bff9a4ddaaf74080fe05d1c61f0f7e0fa635ad691db7ac2928816e0
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_abort(J)I (table at 0x13ac70)
// Calls external APIs: _ZN3PVG15PVGVideoToImage5abortEv, _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGVideoToImage_native_abort"
//   "PVGCodec"

jlong sub_129678(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x129678 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x12967c */ mov x29, sp;
    /* 0x129680 */ cbz x2, #0x129698;
    /* 0x129684 */ mov x0, x2;
    _ZN3PVG15PVGVideoToImage5abortEv();
    /* 0x12968c */ mov w0, wzr;
    /* 0x129690 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x129698 */ adrp x8, #0x13b000;
    /* 0x12969c */ ldr x8, [x8, #0x198];
    /* 0x1296a0 */ ldr w8, [x8];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
