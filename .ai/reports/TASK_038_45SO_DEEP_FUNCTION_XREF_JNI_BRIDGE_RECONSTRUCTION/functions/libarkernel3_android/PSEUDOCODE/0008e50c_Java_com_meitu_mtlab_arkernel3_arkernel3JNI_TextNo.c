// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e50c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setScale
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e50c | Size: 32 bytes | SHA256: eb20cb10cbec5c6460bb13cb1ea2e0bf519031cae5a62c8cfacb367a4765021c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface8setScaleERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setScale(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e50c */ cbz x4, #0x8e51c;
    /* 0x8e510 */ mov x0, x2;
    /* 0x8e514 */ mov x1, x4;
    /* 0x8e518 */ b #0xa1770;
    /* 0x8e51c */ adrp x2, #0x6d000;
    /* 0x8e520 */ add x2, x2, #0xb14;
    /* 0x8e524 */ mov w1, #7;
    /* 0x8e528 */ b #0x882c8;
}
