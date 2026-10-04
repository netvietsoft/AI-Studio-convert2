// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94284
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94284 | Size: 28 bytes | SHA256: c090d9f69024b1273e096945ca9ae38399ba0c249c3bbfd87a7f228171eebc6b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire14requireSkyMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94284 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94288 */ mov x29, sp;
    /* 0x9428c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire14requireSkyMaskEv();
    /* 0x94294 */ and w0, w0, #1;
    /* 0x94298 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
