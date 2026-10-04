// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94444
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94444 | Size: 28 bytes | SHA256: 3c399dde27de8a12a8dc38cab7700d91a5795ca36490fe394ca777846a0c7dc2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireClothMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94444 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94448 */ mov x29, sp;
    /* 0x9444c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireClothMaskAdditionCPUEv();
    /* 0x94454 */ and w0, w0, #1;
    /* 0x94458 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
