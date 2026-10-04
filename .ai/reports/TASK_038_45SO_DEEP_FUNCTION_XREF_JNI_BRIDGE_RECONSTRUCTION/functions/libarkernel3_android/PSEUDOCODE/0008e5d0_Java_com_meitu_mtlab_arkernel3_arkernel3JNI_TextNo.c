// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e5d0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableStroke
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e5d0 | Size: 16 bytes | SHA256: a3c54596448ad97a0a96a4dd57248d472f6e77d771e53c200d211c6cbd16c5a3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface15setEnableStrokeEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableStroke(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e5d0 */ tst w4, #0xff;
    /* 0x8e5d4 */ mov x0, x2;
    /* 0x8e5d8 */ cset w1, ne;
    /* 0x8e5dc */ b #0xa1850;
}
