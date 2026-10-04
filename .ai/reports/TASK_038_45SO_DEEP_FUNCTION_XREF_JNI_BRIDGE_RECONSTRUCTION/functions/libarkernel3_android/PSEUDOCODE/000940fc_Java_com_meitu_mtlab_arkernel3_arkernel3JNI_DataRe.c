// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x940fc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionPosEstimator
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x940fc | Size: 28 bytes | SHA256: 86d143be2a90a60a4a02aff07744dd7ce0a60c8f9e6cdf56183351ebcf12533e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire39requireFaceDL3DDataAdditionPosEstimatorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionPosEstimator(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x940fc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94100 */ mov x29, sp;
    /* 0x94104 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire39requireFaceDL3DDataAdditionPosEstimatorEv();
    /* 0x9410c */ and w0, w0, #1;
    /* 0x94110 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
