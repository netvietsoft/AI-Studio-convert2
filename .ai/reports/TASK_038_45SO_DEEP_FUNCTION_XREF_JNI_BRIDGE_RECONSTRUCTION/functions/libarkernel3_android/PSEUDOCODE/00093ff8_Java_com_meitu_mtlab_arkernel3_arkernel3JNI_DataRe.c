// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93ff8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAddition3DFAMesh
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93ff8 | Size: 28 bytes | SHA256: ccb930cff6a856ea027e79048851b1b84e8d37c9fb470e3905393c08920a4dc6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire31requireFaceDataAddition3DFAMeshEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAddition3DFAMesh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93ff8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93ffc */ mov x29, sp;
    /* 0x94000 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire31requireFaceDataAddition3DFAMeshEv();
    /* 0x94008 */ and w0, w0, #1;
    /* 0x9400c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
