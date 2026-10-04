// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94498
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94498 | Size: 28 bytes | SHA256: e9dcb6e3b2b43245ff4a13181a066b037a300a906225786113318dbbf9543e66
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionCPUEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94498 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9449c */ mov x29, sp;
    /* 0x944a0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionCPUEv();
    /* 0x944a8 */ and w0, w0, #1;
    /* 0x944ac */ ldp x29, x30, [sp], #0x10;
    return x0;
}
