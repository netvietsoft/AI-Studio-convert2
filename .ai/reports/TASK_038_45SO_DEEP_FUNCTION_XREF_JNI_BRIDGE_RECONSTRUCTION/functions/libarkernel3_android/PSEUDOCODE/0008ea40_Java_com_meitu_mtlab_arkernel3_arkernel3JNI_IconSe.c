// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ea40
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1isEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ea40 | Size: 28 bytes | SHA256: 10dfcdbedb03e67f6ab12d9cf2b7a1dc4fd575fff47ba4cb922c24bebea61dcc
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326IconSequenceColorInterface10isEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1isEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ea40 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ea44 */ mov x29, sp;
    /* 0x8ea48 */ mov x0, x2;
    _ZNK8mtlabar326IconSequenceColorInterface10isEditableEv();
    /* 0x8ea50 */ and w0, w0, #1;
    /* 0x8ea54 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
