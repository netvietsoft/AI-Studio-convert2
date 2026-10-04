// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ea30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ea30 | Size: 16 bytes | SHA256: 5134ea56870b62dcc400c4b379e4cee901d79896dbd3947c9e0b1aff324f07d2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceColorInterface11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8ea30 */ tst w4, #0xff;
    /* 0x8ea34 */ mov x0, x2;
    /* 0x8ea38 */ cset w1, ne;
    /* 0x8ea3c */ b #0xa1ac0;
}
