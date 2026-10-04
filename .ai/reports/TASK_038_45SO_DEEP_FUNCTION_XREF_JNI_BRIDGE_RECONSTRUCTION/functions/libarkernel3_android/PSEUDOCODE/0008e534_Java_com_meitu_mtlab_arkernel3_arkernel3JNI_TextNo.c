// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e534
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setOnTopOfText
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e534 | Size: 16 bytes | SHA256: 051014e22e98762c3348c56539733c551e5936b8ccad0a7f43f015d1e3ec9637
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface14setOnTopOfTextEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setOnTopOfText(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e534 */ tst w4, #0xff;
    /* 0x8e538 */ mov x0, x2;
    /* 0x8e53c */ cset w1, ne;
    /* 0x8e540 */ b #0xa1790;
}
