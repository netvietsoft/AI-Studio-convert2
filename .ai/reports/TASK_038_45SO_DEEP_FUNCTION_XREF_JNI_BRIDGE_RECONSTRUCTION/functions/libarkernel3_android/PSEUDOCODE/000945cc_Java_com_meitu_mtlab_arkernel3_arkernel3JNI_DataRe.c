// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x945cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARWorldTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x945cc | Size: 28 bytes | SHA256: 273431c4862633eef577dfd94e2f313b96ab98e4ceb9bc7ae012bb04aa72ecc1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireARWorldTrackingEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARWorldTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x945cc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x945d0 */ mov x29, sp;
    /* 0x945d4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireARWorldTrackingEv();
    /* 0x945dc */ and w0, w0, #1;
    /* 0x945e0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
