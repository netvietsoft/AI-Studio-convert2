// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95ac0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setCurPoint
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95ac0 | Size: 32 bytes | SHA256: bf67a1324aa0ec0dd6b0c8b7c5ba6dce40a46ce0a92f45d062b41ead1610a919
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache11setCurPointERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setCurPoint(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95ac0 */ cbz x4, #0x95ad0;
    /* 0x95ac4 */ mov x0, x2;
    /* 0x95ac8 */ mov x1, x4;
    /* 0x95acc */ b #0xa4980;
    /* 0x95ad0 */ adrp x2, #0x6d000;
    /* 0x95ad4 */ add x2, x2, #0xcd3;
    /* 0x95ad8 */ mov w1, #7;
    /* 0x95adc */ b #0x882c8;
}
