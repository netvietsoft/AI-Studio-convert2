// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x940a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace3DReconstructorData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x940a0 | Size: 28 bytes | SHA256: 586d1049ce5a4814affc2fd613fd42d9fd9bddedd74356a9d1dd9e2a3c317c06
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire30requireFace3DReconstructorDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace3DReconstructorData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x940a0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x940a4 */ mov x29, sp;
    /* 0x940a8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire30requireFace3DReconstructorDataEv();
    /* 0x940b0 */ and w0, w0, #1;
    /* 0x940b4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
