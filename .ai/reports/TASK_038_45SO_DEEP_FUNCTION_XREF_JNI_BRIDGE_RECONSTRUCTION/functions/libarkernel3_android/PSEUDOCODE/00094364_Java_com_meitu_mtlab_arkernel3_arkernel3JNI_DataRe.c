// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94364
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94364 | Size: 28 bytes | SHA256: 98f23308a36873cb840be6f3041b1337336ec764582c9c4f03553b8bddcdb1b9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireHeadMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94364 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94368 */ mov x29, sp;
    /* 0x9436c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireHeadMaskAdditionGPUEv();
    /* 0x94374 */ and w0, w0, #1;
    /* 0x94378 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
