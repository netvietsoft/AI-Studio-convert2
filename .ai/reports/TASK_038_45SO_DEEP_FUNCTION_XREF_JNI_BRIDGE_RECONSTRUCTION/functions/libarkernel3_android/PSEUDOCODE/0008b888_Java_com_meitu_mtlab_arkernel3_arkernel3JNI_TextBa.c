// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b888
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b888 | Size: 28 bytes | SHA256: 2703a3f280446d3218ebf6f657956c34ac7939de83dc20dcca96f5f50b7dca96
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar332TextBackgroundColorConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBackgroundColorConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b888 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8b88c */ mov x29, sp;
    /* 0x8b890 */ mov x0, x2;
    _ZNK8mtlabar332TextBackgroundColorConfiguration11getEditableEv();
    /* 0x8b898 */ and w0, w0, #1;
    /* 0x8b89c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
