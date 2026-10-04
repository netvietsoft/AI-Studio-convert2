// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93f50
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionPosEstimator
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93f50 | Size: 28 bytes | SHA256: 4f4c873b988662d096bd9ee65be19769fb0f57843a43d3c064ffebc087c93a48
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire35requireFaceDataAdditionPosEstimatorEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionPosEstimator(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93f50 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f54 */ mov x29, sp;
    /* 0x93f58 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire35requireFaceDataAdditionPosEstimatorEv();
    /* 0x93f60 */ and w0, w0, #1;
    /* 0x93f64 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
