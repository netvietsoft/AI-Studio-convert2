// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94690
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCGAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94690 | Size: 28 bytes | SHA256: 74459d9b7eba6df941a667ce44ef9b2169c9465c5fef947347107c55f8b34737
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire20requireCGAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCGAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94690 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94694 */ mov x29, sp;
    /* 0x94698 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire20requireCGAdditionGPUEv();
    /* 0x946a0 */ and w0, w0, #1;
    /* 0x946a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
