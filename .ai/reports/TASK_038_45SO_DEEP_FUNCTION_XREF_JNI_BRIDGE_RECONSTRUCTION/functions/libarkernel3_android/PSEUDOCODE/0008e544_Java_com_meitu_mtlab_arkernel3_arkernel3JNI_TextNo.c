// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e544
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getOnTopOfText
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e544 | Size: 28 bytes | SHA256: efe0595d179fe67ed0f7b69ad2381e136824bcca487526940894385ce38c8250
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface14getOnTopOfTextEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getOnTopOfText(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e544 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e548 */ mov x29, sp;
    /* 0x8e54c */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface14getOnTopOfTextEv();
    /* 0x8e554 */ and w0, w0, #1;
    /* 0x8e558 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
