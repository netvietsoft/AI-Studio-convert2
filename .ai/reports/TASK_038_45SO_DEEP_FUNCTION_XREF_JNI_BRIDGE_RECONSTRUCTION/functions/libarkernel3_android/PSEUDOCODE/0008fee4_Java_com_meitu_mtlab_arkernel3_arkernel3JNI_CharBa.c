// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fee4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fee4 | Size: 28 bytes | SHA256: 710864e9cbdd21070c6e1be8aa057b862436195b4e5c444f5e7e5e6f517f3e65
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323CharBackgroundInterface11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8fee4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8fee8 */ mov x29, sp;
    /* 0x8feec */ mov x0, x2;
    _ZNK8mtlabar323CharBackgroundInterface11getEditableEv();
    /* 0x8fef4 */ and w0, w0, #1;
    /* 0x8fef8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
