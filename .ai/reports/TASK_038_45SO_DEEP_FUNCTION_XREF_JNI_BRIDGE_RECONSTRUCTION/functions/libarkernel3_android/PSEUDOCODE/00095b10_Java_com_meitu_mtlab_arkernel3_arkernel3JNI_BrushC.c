// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95b10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setLastPoint
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95b10 | Size: 32 bytes | SHA256: ba28a90e190a304e94178dd5981b290c7dff6e1ca71e1a1623058a180fbf2f92
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache12setLastPointERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setLastPoint(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95b10 */ cbz x4, #0x95b20;
    /* 0x95b14 */ mov x0, x2;
    /* 0x95b18 */ mov x1, x4;
    /* 0x95b1c */ b #0xa49c0;
    /* 0x95b20 */ adrp x2, #0x6d000;
    /* 0x95b24 */ add x2, x2, #0xcd3;
    /* 0x95b28 */ mov w1, #7;
    /* 0x95b2c */ b #0x882c8;
}
