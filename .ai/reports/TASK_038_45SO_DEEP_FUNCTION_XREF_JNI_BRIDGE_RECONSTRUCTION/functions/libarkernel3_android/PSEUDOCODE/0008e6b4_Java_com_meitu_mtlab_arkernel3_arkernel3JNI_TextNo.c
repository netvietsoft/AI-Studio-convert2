// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e6b4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableOpacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e6b4 | Size: 16 bytes | SHA256: f25071984ce43117b189c2e2951efd63b5ff17237c44bca7b7ac1a931a79007b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface16setEnableOpacityEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setEnableOpacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e6b4 */ tst w4, #0xff;
    /* 0x8e6b8 */ mov x0, x2;
    /* 0x8e6bc */ cset w1, ne;
    /* 0x8e6c0 */ b #0xa18b0;
}
