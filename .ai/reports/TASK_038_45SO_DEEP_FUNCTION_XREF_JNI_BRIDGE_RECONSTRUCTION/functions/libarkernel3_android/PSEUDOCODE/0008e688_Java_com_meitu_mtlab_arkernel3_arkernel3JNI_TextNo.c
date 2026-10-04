// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e688
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableTaper
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e688 | Size: 16 bytes | SHA256: 3aaa5eb278b3421a6db9df9b830961fbad527394426eed194fe558a3dae26c4e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface14setEnableTaperEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableTaper(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e688 */ tst w4, #0xff;
    /* 0x8e68c */ mov x0, x2;
    /* 0x8e690 */ cset w1, ne;
    /* 0x8e694 */ b #0xa1890;
}
