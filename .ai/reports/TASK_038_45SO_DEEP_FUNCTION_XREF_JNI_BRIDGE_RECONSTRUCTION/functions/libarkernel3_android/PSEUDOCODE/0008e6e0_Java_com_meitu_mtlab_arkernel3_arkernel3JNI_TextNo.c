// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e6e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setSizeRange
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e6e0 | Size: 32 bytes | SHA256: bebdd9909180f580638ff36c1adae0cff8e4952d450f840a3635ed8efcb86b1b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface12setSizeRangeERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE
// Strings referenced:
//   "std::vector< int > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setSizeRange(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e6e0 */ cbz x4, #0x8e6f0;
    /* 0x8e6e4 */ mov x0, x2;
    /* 0x8e6e8 */ mov x1, x4;
    /* 0x8e6ec */ b #0xa18d0;
    /* 0x8e6f0 */ adrp x2, #0x6d000;
    /* 0x8e6f4 */ add x2, x2, #0x988;
    /* 0x8e6f8 */ mov w1, #7;
    /* 0x8e6fc */ b #0x882c8;
}
