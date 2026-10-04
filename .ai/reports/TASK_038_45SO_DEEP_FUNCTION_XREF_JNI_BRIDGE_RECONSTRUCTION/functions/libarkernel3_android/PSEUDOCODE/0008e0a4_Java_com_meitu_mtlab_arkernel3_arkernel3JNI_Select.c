// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e0a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setOffset
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e0a4 | Size: 32 bytes | SHA256: 42022a2a0f7e73c81001b06b0dc381799845d035479bc98de83872e1847493df
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface9setOffsetERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setOffset(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e0a4 */ cbz x4, #0x8e0b4;
    /* 0x8e0a8 */ mov x0, x2;
    /* 0x8e0ac */ mov x1, x4;
    /* 0x8e0b0 */ b #0xa14f0;
    /* 0x8e0b4 */ adrp x2, #0x6d000;
    /* 0x8e0b8 */ add x2, x2, #0xb14;
    /* 0x8e0bc */ mov w1, #7;
    /* 0x8e0c0 */ b #0x882c8;
}
