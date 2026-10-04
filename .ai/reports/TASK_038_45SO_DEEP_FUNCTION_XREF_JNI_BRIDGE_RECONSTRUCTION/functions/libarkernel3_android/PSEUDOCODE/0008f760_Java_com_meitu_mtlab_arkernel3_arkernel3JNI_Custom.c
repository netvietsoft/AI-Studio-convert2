// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f760
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnableRotate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f760 | Size: 28 bytes | SHA256: 7df4e23a632abd1ecd30315204330392581afbc5764b0914449b7661146680d8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324CustomTransformInterface15getEnableRotateEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnableRotate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f760 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f764 */ mov x29, sp;
    /* 0x8f768 */ mov x0, x2;
    _ZNK8mtlabar324CustomTransformInterface15getEnableRotateEv();
    /* 0x8f770 */ and w0, w0, #1;
    /* 0x8f774 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
