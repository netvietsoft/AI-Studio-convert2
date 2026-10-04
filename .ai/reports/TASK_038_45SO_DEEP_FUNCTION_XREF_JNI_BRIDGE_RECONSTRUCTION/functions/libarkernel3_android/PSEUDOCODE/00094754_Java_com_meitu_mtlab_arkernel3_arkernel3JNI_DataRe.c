// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94754
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireMultiInstanceMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94754 | Size: 28 bytes | SHA256: 8652c73f13165539a0ce43e0211ddd2d37ec5f76b5e1ed2c5522af3945f52031
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire24requireMultiInstanceMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireMultiInstanceMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94754 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94758 */ mov x29, sp;
    /* 0x9475c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire24requireMultiInstanceMaskEv();
    /* 0x94764 */ and w0, w0, #1;
    /* 0x94768 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
