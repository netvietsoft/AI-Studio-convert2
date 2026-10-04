// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9404c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV2Data
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9404c | Size: 28 bytes | SHA256: 71c2fb51fffd1ae4bfa6b90de4b22034d260302c192483e100b20949cede160d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV2DataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DReconstructorV2Data(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9404c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94050 */ mov x29, sp;
    /* 0x94054 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireFace2DReconstructorV2DataEv();
    /* 0x9405c */ and w0, w0, #1;
    /* 0x94060 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
