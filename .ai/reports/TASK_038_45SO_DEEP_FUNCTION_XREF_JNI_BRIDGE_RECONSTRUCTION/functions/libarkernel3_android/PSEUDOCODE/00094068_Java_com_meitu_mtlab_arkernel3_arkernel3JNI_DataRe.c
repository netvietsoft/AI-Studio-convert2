// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94068
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV3Data
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94068 | Size: 28 bytes | SHA256: d645407a7dd0086d6964ddd0b351ac2327ae8b8b24fbe9749fc6b614d3d5be8d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV3DataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV3Data(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94068 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9406c */ mov x29, sp;
    /* 0x94070 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV3DataEv();
    /* 0x94078 */ and w0, w0, #1;
    /* 0x9407c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
