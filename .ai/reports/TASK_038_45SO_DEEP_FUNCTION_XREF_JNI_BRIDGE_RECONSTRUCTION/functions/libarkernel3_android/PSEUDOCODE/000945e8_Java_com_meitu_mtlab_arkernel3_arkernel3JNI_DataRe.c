// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x945e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARPlaneAnchor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x945e8 | Size: 28 bytes | SHA256: 0a67c2df125ab68dbf83a3ee27a0298c6dcdc478046ea418ca14ae907549b7bb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire20requireARPlaneAnchorEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARPlaneAnchor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x945e8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x945ec */ mov x29, sp;
    /* 0x945f0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire20requireARPlaneAnchorEv();
    /* 0x945f8 */ and w0, w0, #1;
    /* 0x945fc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
