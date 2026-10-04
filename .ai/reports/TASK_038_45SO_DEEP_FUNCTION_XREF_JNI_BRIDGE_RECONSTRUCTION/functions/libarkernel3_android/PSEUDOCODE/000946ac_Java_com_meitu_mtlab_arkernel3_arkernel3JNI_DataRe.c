// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x946ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCompactBeautyData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x946ac | Size: 28 bytes | SHA256: 4f5c5e1a07b3b37e0209f0d7f24d788b87c9dc5548731370c6a1286bb6390a47
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire24requireCompactBeautyDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCompactBeautyData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x946ac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x946b0 */ mov x29, sp;
    /* 0x946b4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire24requireCompactBeautyDataEv();
    /* 0x946bc */ and w0, w0, #1;
    /* 0x946c0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
