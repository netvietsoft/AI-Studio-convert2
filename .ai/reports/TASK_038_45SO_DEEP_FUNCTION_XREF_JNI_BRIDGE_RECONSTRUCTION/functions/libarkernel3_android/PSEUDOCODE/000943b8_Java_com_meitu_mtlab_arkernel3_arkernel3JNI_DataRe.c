// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x943b8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNevusMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x943b8 | Size: 28 bytes | SHA256: a6d07868dd23cb0783fed6190d8430a8ec080534975f752830233215540244a2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireNevusMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireNevusMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x943b8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x943bc */ mov x29, sp;
    /* 0x943c0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireNevusMaskAdditionGPUEv();
    /* 0x943c8 */ and w0, w0, #1;
    /* 0x943cc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
