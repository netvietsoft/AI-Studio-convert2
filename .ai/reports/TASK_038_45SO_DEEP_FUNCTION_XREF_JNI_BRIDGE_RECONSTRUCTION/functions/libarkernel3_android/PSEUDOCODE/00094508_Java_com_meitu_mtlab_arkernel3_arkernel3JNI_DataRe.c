// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94508
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyInOne
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94508 | Size: 28 bytes | SHA256: 1a7881982e75107631555e0a10de0478a39f8030c50a70ef0e41d8c60df9b7fa
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire16requireBodyInOneEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyInOne(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94508 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9450c */ mov x29, sp;
    /* 0x94510 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire16requireBodyInOneEv();
    /* 0x94518 */ and w0, w0, #1;
    /* 0x9451c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
