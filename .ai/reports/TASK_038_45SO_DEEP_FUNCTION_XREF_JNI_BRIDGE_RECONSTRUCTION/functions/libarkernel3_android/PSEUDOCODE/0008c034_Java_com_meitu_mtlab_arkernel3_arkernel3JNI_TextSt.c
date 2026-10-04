// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c034
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c034 | Size: 28 bytes | SHA256: 96d9ced5a056743e0e942f98a8895be85c824b34254f3216a34e562fcfcdab6d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextStrokeConfiguration12getColorWorkEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8c034 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8c038 */ mov x29, sp;
    /* 0x8c03c */ mov x0, x2;
    _ZNK8mtlabar323TextStrokeConfiguration12getColorWorkEv();
    /* 0x8c044 */ and w0, w0, #1;
    /* 0x8c048 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
