// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94084
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DBackgroundReconstructorData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94084 | Size: 28 bytes | SHA256: dce460e690aac5dbcbc2cfacd396b138cf2818853e7643185ccd557f1d8e1788
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire40requireFace2DBackgroundReconstructorDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFace2DBackgroundReconstructorData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94084 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94088 */ mov x29, sp;
    /* 0x9408c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire40requireFace2DBackgroundReconstructorDataEv();
    /* 0x94094 */ and w0, w0, #1;
    /* 0x94098 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
