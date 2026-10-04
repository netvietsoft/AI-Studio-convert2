// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bf7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bf7c | Size: 28 bytes | SHA256: 743ad3922641db90699c5e6b8c02f9616dc1e073fbcc21c3b184e411e8faca86
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextStrokeConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bf7c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8bf80 */ mov x29, sp;
    /* 0x8bf84 */ mov x0, x2;
    _ZNK8mtlabar323TextStrokeConfiguration11getEditableEv();
    /* 0x8bf8c */ and w0, w0, #1;
    /* 0x8bf90 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
