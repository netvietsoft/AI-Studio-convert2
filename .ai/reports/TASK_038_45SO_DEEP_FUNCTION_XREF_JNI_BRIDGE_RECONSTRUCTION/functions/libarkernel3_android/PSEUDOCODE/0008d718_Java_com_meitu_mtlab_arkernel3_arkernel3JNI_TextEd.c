// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d718
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d718 | Size: 28 bytes | SHA256: 488db542d2100e8bfabc1d7a112ca912017bdf501c23e7c260d888b488d27dd3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar325TextEditableConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d718 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d71c */ mov x29, sp;
    /* 0x8d720 */ mov x0, x2;
    _ZNK8mtlabar325TextEditableConfiguration11getEditableEv();
    /* 0x8d728 */ and w0, w0, #1;
    /* 0x8d72c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
