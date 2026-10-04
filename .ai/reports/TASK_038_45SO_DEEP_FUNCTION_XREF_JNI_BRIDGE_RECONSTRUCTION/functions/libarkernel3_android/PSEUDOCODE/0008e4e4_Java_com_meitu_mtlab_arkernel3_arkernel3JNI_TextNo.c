// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e4e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setOffset
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e4e4 | Size: 32 bytes | SHA256: 9d7b04155e42b810333681a040f85b7a3d87fcec111796a9b376c82cdff8bd68
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface9setOffsetERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setOffset(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e4e4 */ cbz x4, #0x8e4f4;
    /* 0x8e4e8 */ mov x0, x2;
    /* 0x8e4ec */ mov x1, x4;
    /* 0x8e4f0 */ b #0xa1750;
    /* 0x8e4f4 */ adrp x2, #0x6d000;
    /* 0x8e4f8 */ add x2, x2, #0xb14;
    /* 0x8e4fc */ mov w1, #7;
    /* 0x8e500 */ b #0x882c8;
}
