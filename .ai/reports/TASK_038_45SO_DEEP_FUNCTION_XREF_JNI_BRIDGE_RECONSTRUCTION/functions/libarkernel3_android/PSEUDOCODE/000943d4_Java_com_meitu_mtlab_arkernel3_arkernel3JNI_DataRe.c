// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x943d4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x943d4 | Size: 28 bytes | SHA256: cc173837f54c034003755a1585bf0622a725384830a9e0a7a01b54c0fdd7b81f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireFaceContourMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x943d4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x943d8 */ mov x29, sp;
    /* 0x943dc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireFaceContourMaskEv();
    /* 0x943e4 */ and w0, w0, #1;
    /* 0x943e8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
