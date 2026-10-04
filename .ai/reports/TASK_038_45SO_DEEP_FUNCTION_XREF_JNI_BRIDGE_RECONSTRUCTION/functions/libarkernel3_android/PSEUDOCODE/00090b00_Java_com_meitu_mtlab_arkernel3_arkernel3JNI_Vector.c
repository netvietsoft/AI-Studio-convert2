// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90b00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90b00 | Size: 20 bytes | SHA256: cc6b329e1896ca42a8466048f0392a5e1625f3e00a91b53ff428420969e5ca23
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x90b00 */ ldr x8, [x2, #0x10];
    /* 0x90b04 */ ldr x9, [x2];
    /* 0x90b08 */ sub x8, x8, x9;
    /* 0x90b0c */ asr x0, x8, #3;
    return x0;
}
