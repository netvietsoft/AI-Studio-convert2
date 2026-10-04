// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f1e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setPadding
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f1e8 | Size: 32 bytes | SHA256: 172accf8f84c4b83008511c0032bf99e9a7da8f6b187b4c685d2ae532e4ef094
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326CharSVGBackgroundInterface10setPaddingERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setPadding(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f1e8 */ cbz x4, #0x8f1f8;
    /* 0x8f1ec */ mov x0, x2;
    /* 0x8f1f0 */ mov x1, x4;
    /* 0x8f1f4 */ b #0xa1fb0;
    /* 0x8f1f8 */ adrp x2, #0x6d000;
    /* 0x8f1fc */ add x2, x2, #0xb14;
    /* 0x8f200 */ mov w1, #7;
    /* 0x8f204 */ b #0x882c8;
}
