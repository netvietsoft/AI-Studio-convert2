// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e8c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e8c | Size: 28 bytes | SHA256: c9187051a979357da652b4b727784ece4a93531ac96f551ecf01ecb4a0db5ea8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireFaceDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e8c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e90 */ mov x29, sp;
    /* 0x93e94 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireFaceDataEv();
    /* 0x93e9c */ and w0, w0, #1;
    /* 0x93ea0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
