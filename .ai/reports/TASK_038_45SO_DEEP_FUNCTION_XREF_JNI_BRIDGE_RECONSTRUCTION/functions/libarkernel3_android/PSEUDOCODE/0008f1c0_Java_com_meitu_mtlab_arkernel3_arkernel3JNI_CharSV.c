// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f1c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setOffset
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f1c0 | Size: 32 bytes | SHA256: 0a839f67cce6801ec6641005748ccecb48b2bd468503494b7bc5f944e4635371
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326CharSVGBackgroundInterface9setOffsetERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setOffset(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f1c0 */ cbz x4, #0x8f1d0;
    /* 0x8f1c4 */ mov x0, x2;
    /* 0x8f1c8 */ mov x1, x4;
    /* 0x8f1cc */ b #0xa1f90;
    /* 0x8f1d0 */ adrp x2, #0x6d000;
    /* 0x8f1d4 */ add x2, x2, #0xb14;
    /* 0x8f1d8 */ mov w1, #7;
    /* 0x8f1dc */ b #0x882c8;
}
