// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e560
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setAnimate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e560 | Size: 16 bytes | SHA256: 0a524fb48f4801872bc65b05ec158dc5bfe2f637a244057f0ed73d41a75f9630
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface10setAnimateEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setAnimate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e560 */ tst w4, #0xff;
    /* 0x8e564 */ mov x0, x2;
    /* 0x8e568 */ cset w1, ne;
    /* 0x8e56c */ b #0xa17b0;
}
