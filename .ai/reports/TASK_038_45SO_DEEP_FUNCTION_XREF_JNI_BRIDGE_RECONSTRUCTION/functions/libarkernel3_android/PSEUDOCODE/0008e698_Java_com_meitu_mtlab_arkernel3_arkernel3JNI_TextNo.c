// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e698
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableTaper
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e698 | Size: 28 bytes | SHA256: 4ff855f3baba21dbb59910993cb2e31701934efcb671bbf931b5c96f7d080da1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface14getEnableTaperEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableTaper(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e698 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e69c */ mov x29, sp;
    /* 0x8e6a0 */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface14getEnableTaperEv();
    /* 0x8e6a8 */ and w0, w0, #1;
    /* 0x8e6ac */ ldp x29, x30, [sp], #0x10;
    return x0;
}
