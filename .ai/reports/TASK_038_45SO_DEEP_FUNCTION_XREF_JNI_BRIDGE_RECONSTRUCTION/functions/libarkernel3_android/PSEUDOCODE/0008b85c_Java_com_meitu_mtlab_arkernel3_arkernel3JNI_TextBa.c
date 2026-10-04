// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b85c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b85c | Size: 28 bytes | SHA256: b9436b5a2f2492ab0f3fbf6b9593da3254a11c3f91d1612f0a127747c26d8f5d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar332TextBackgroundColorConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b85c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8b860 */ mov x29, sp;
    /* 0x8b864 */ mov x0, x2;
    _ZNK8mtlabar332TextBackgroundColorConfiguration9getEnableEv();
    /* 0x8b86c */ and w0, w0, #1;
    /* 0x8b870 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
