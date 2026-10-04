// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d9c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getPerpendicular
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d9c8 | Size: 28 bytes | SHA256: f15eaa030e9ad4faff28f85a606df50527b537650fcd4c744cf9ab411f344a2e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration16getPerpendicularEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getPerpendicular(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d9c8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d9cc */ mov x29, sp;
    /* 0x8d9d0 */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration16getPerpendicularEv();
    /* 0x8d9d8 */ and w0, w0, #1;
    /* 0x8d9dc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
