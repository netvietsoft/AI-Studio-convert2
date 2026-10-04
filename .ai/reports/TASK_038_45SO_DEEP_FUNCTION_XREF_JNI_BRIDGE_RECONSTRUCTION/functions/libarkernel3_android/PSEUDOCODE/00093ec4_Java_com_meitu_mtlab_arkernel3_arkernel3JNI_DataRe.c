// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93ec4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionHead
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93ec4 | Size: 28 bytes | SHA256: 870104e4e3ba730212bd33c3a319e5f568467ccecb8affe9e595379ef8d2b8a9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireFaceDataAdditionHeadEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionHead(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93ec4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93ec8 */ mov x29, sp;
    /* 0x93ecc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireFaceDataAdditionHeadEv();
    /* 0x93ed4 */ and w0, w0, #1;
    /* 0x93ed8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
