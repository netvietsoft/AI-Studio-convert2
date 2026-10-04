// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93efc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionNeck
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93efc | Size: 28 bytes | SHA256: 8189ba92f7b5bf685b74a81d562904648a35f71ddfcafd8a731421c384a8e2f0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireFaceDataAdditionNeckEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionNeck(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93efc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f00 */ mov x29, sp;
    /* 0x93f04 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireFaceDataAdditionNeckEv();
    /* 0x93f0c */ and w0, w0, #1;
    /* 0x93f10 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
