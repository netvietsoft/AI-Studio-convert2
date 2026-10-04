// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94604
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARLightEstimate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94604 | Size: 28 bytes | SHA256: 5024b8618e7225c0242c08b52d9321bb082029df7530201bbc60a44cc4c79ce8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireARLightEstimateEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARLightEstimate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94604 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94608 */ mov x29, sp;
    /* 0x9460c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireARLightEstimateEv();
    /* 0x94614 */ and w0, w0, #1;
    /* 0x94618 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
