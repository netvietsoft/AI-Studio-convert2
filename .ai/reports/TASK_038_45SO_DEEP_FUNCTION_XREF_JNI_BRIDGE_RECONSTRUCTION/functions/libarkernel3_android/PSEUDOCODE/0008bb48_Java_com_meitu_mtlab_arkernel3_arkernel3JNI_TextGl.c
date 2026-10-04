// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bb48
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bb48 | Size: 28 bytes | SHA256: 5314a0bdf3b7d0ece1a44c0ffac24181eba93462adbdf02815d641071f31de1c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextGlowConfiguration12getColorWorkEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bb48 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8bb4c */ mov x29, sp;
    /* 0x8bb50 */ mov x0, x2;
    _ZNK8mtlabar321TextGlowConfiguration12getColorWorkEv();
    /* 0x8bb58 */ and w0, w0, #1;
    /* 0x8bb5c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
