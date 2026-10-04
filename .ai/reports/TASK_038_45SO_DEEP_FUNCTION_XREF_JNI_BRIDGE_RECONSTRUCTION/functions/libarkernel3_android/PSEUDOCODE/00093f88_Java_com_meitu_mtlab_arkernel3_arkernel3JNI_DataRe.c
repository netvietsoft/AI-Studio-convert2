// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93f88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionAge
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93f88 | Size: 28 bytes | SHA256: 5010a9c2d58c4999181d0956b64485889ab5965d99bcda0e0de75c423e5f23db
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireFaceDataAdditionAgeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionAge(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93f88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f8c */ mov x29, sp;
    /* 0x93f90 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireFaceDataAdditionAgeEv();
    /* 0x93f98 */ and w0, w0, #1;
    /* 0x93f9c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
