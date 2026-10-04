// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d770
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getLineSpacingEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d770 | Size: 28 bytes | SHA256: df3ba13083d4225540e72eb37cdd19e1cf0b7687606df8b3d1243b8d13982709
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar325TextEditableConfiguration22getLineSpacingEditableEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getLineSpacingEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d770 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d774 */ mov x29, sp;
    /* 0x8d778 */ mov x0, x2;
    _ZNK8mtlabar325TextEditableConfiguration22getLineSpacingEditableEv();
    /* 0x8d780 */ and w0, w0, #1;
    /* 0x8d784 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
