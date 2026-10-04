// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d9f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getReverse
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d9f4 | Size: 28 bytes | SHA256: c8d76bd49ac0a3dd4d1a924e1efb0149d0fa5e759fe006853d28864b8b3ae94e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration10getReverseEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getReverse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d9f4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d9f8 */ mov x29, sp;
    /* 0x8d9fc */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration10getReverseEv();
    /* 0x8da04 */ and w0, w0, #1;
    /* 0x8da08 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
