// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e4ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setSpacing
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e4ac | Size: 32 bytes | SHA256: 0e71f5da2f373095611ec9a21815a8fce8397f0ef606fe3aa903a12ad3c53f63
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface10setSpacingERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setSpacing(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e4ac */ cbz x4, #0x8e4bc;
    /* 0x8e4b0 */ mov x0, x2;
    /* 0x8e4b4 */ mov x1, x4;
    /* 0x8e4b8 */ b #0xa1710;
    /* 0x8e4bc */ adrp x2, #0x6d000;
    /* 0x8e4c0 */ add x2, x2, #0xb14;
    /* 0x8e4c4 */ mov w1, #7;
    /* 0x8e4c8 */ b #0x882c8;
}
