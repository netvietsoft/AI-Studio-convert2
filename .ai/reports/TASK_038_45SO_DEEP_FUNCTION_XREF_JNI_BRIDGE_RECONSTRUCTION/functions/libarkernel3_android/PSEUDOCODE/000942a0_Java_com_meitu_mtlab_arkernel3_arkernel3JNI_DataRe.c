// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x942a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x942a0 | Size: 28 bytes | SHA256: 24b644c23cae6a881cc32c8ac2b124dd600f33f3044d1ac2e5a97d41b137fec0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire25requireSkyMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x942a0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x942a4 */ mov x29, sp;
    /* 0x942a8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire25requireSkyMaskAdditionCPUEv();
    /* 0x942b0 */ and w0, w0, #1;
    /* 0x942b4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
