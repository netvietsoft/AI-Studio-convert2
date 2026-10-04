// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d744
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getSpacingEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d744 | Size: 28 bytes | SHA256: 67dff39e58d9fc4d9bd84a282ef64fa3540a3ea357ea318623e7b24923a7a8ae
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar325TextEditableConfiguration18getSpacingEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getSpacingEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d744 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d748 */ mov x29, sp;
    /* 0x8d74c */ mov x0, x2;
    _ZNK8mtlabar325TextEditableConfiguration18getSpacingEditableEv();
    /* 0x8d754 */ and w0, w0, #1;
    /* 0x8d758 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
