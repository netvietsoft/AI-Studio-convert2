// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9440c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9440c | Size: 28 bytes | SHA256: 10dd2f28f26b3599a293ab22146d777393a89390a5985b5ff4ae1adee70eeac2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9440c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94410 */ mov x29, sp;
    /* 0x94414 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionGPUEv();
    /* 0x9441c */ and w0, w0, #1;
    /* 0x94420 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
