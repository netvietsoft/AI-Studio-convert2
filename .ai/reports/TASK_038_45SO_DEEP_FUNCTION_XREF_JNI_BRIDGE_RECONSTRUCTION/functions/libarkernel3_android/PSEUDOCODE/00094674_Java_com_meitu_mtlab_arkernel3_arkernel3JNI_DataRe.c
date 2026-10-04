// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94674
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCGAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94674 | Size: 28 bytes | SHA256: b007b03a40f1c2b8d66d783752bdfd3c64cda1257ebe5aa95c23374103fd99dd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire20requireCGAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCGAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94674 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94678 */ mov x29, sp;
    /* 0x9467c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire20requireCGAdditionCPUEv();
    /* 0x94684 */ and w0, w0, #1;
    /* 0x94688 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
