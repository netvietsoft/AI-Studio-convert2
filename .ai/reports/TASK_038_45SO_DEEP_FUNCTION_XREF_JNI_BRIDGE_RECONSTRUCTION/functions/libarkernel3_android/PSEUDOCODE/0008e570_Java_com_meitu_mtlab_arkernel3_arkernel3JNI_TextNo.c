// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e570
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getAnimate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e570 | Size: 28 bytes | SHA256: 797cedd584c4ade7b0ab9e7cb4f3959bde1c93a8737dcc5927bec4c3613b2c49
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface10getAnimateEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getAnimate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e570 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e574 */ mov x29, sp;
    /* 0x8e578 */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface10getAnimateEv();
    /* 0x8e580 */ and w0, w0, #1;
    /* 0x8e584 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
