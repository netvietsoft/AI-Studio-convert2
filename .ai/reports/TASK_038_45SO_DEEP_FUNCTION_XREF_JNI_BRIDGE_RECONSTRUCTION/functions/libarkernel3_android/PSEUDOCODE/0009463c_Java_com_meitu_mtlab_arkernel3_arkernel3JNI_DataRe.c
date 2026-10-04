// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9463c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARSkeleton
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9463c | Size: 28 bytes | SHA256: fac3a4d6f0c50d0b02b05e577de3e086d3b4f395344eb902f5ae79e943ae86d3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire17requireARSkeletonEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARSkeleton(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9463c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94640 */ mov x29, sp;
    /* 0x94644 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire17requireARSkeletonEv();
    /* 0x9464c */ and w0, w0, #1;
    /* 0x94650 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
