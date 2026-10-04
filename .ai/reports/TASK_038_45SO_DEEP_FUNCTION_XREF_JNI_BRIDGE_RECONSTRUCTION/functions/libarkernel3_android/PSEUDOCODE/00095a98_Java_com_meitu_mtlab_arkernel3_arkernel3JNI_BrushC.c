// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95a98
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setPrePoint
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95a98 | Size: 32 bytes | SHA256: b464c0d35732e170484c538f1f3f1a70ec4c36ee652641116d5eec44b47664bc
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache11setPrePointERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setPrePoint(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95a98 */ cbz x4, #0x95aa8;
    /* 0x95a9c */ mov x0, x2;
    /* 0x95aa0 */ mov x1, x4;
    /* 0x95aa4 */ b #0xa4960;
    /* 0x95aa8 */ adrp x2, #0x6d000;
    /* 0x95aac */ add x2, x2, #0xcd3;
    /* 0x95ab0 */ mov w1, #7;
    /* 0x95ab4 */ b #0x882c8;
}
