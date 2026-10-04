// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e918
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1setDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e918 | Size: 16 bytes | SHA256: f21b26a133b155fa09ccbd865b1a3ca33ee731d41e95b4c1e6f3d7c9d9e4165e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322SelectionNoteInterface19setDisplayInASRTimeEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1setDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e918 */ tst w4, #0xff;
    /* 0x8e91c */ mov x0, x2;
    /* 0x8e920 */ cset w1, ne;
    /* 0x8e924 */ b #0xa19f0;
}
