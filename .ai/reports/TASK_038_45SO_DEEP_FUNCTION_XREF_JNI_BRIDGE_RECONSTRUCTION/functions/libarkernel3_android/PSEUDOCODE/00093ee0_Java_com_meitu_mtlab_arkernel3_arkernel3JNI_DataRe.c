// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93ee0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEar
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93ee0 | Size: 28 bytes | SHA256: 99df00df0cd94f1a53c8c6cd7f5aad33b8115f61bba896926672c5bd7f7a8898
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireFaceDataAdditionEarEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEar(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93ee0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93ee4 */ mov x29, sp;
    /* 0x93ee8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireFaceDataAdditionEarEv();
    /* 0x93ef0 */ and w0, w0, #1;
    /* 0x93ef4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
