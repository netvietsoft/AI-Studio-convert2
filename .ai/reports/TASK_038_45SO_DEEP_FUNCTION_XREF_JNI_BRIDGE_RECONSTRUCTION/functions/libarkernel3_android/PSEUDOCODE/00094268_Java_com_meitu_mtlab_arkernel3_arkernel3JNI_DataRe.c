// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94268
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94268 | Size: 28 bytes | SHA256: 1dcf4af97c4cc6493776196bb5294bc49fc47ce24d329e1a6d04d6890938cd57
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireHairMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94268 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9426c */ mov x29, sp;
    /* 0x94270 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireHairMaskAdditionGPUEv();
    /* 0x94278 */ and w0, w0, #1;
    /* 0x9427c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
