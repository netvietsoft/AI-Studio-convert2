// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e5e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableStroke
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e5e0 | Size: 28 bytes | SHA256: 0a27ed812c95588dfc68a7a19fdc6083f51f2a7f5064c109922000e42e2f9cd6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface15getEnableStrokeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableStroke(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e5e0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e5e4 */ mov x29, sp;
    /* 0x8e5e8 */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface15getEnableStrokeEv();
    /* 0x8e5f0 */ and w0, w0, #1;
    /* 0x8e5f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
