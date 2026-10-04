// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94030
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV1Data
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94030 | Size: 28 bytes | SHA256: 28628b2a89cd2a070fef065170d94ae923f36aa0115c3d7b16c3e78092cf323e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV1DataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV1Data(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94030 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94034 */ mov x29, sp;
    /* 0x94038 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV1DataEv();
    /* 0x94040 */ and w0, w0, #1;
    /* 0x94044 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
