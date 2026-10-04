// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x944b4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x944b4 | Size: 28 bytes | SHA256: a3bf2980e068e8d9fabf00bb1b864edfc6b286dbeabc02bd7d1ae42b53638d9b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionGPUEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x944b4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x944b8 */ mov x29, sp;
    /* 0x944bc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionGPUEv();
    /* 0x944c4 */ and w0, w0, #1;
    /* 0x944c8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
