// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d7f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getPinyinEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d7f4 | Size: 28 bytes | SHA256: 81e6ef00734782b88e54a2d2a6cb04d3f0f1b53e1329ccffb77d03bfc845174b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar325TextEditableConfiguration17getPinyinEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getPinyinEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d7f4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d7f8 */ mov x29, sp;
    /* 0x8d7fc */ mov x0, x2;
    _ZNK8mtlabar325TextEditableConfiguration17getPinyinEditableEv();
    /* 0x8d804 */ and w0, w0, #1;
    /* 0x8d808 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
