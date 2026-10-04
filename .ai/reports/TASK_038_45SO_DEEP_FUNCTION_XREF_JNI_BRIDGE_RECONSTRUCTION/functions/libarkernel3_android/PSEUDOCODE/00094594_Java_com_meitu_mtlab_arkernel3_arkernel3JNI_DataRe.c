// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94594
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARFaceMesh
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94594 | Size: 28 bytes | SHA256: 38212764c184b901543fae3331fa1e3106bcbea57abc19b816c49dcb6219eb6a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire17requireARFaceMeshEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARFaceMesh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94594 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94598 */ mov x29, sp;
    /* 0x9459c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire17requireARFaceMeshEv();
    /* 0x945a4 */ and w0, w0, #1;
    /* 0x945a8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
