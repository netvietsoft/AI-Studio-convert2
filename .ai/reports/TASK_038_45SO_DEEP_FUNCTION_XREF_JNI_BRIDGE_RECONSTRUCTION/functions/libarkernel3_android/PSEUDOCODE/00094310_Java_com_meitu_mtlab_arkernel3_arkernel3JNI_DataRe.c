// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94310
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94310 | Size: 28 bytes | SHA256: 3604cfd7ec26ef7150a4c33b05932f3b54e4d1c46b93c653deeb2f1c09c78df0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireSkinMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94310 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94314 */ mov x29, sp;
    /* 0x94318 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireSkinMaskAdditionGPUEv();
    /* 0x94320 */ and w0, w0, #1;
    /* 0x94324 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
