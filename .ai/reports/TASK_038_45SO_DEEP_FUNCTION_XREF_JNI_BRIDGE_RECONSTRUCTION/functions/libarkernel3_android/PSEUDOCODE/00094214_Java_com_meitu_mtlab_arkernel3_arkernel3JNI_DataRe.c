// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94214
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94214 | Size: 28 bytes | SHA256: 5d1879488d2667d777f31a8e6f16be122a11a3139cc9ff7230a91fef27357b8a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireBodyMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94214 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94218 */ mov x29, sp;
    /* 0x9421c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireBodyMaskAdditionGPUEv();
    /* 0x94224 */ and w0, w0, #1;
    /* 0x94228 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
