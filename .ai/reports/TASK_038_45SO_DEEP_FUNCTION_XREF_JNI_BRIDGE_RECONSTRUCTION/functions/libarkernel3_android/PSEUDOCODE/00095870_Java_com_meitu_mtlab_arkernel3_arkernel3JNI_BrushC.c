// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95870
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95870 | Size: 32 bytes | SHA256: 3eca14935dd7baaa08e207e6bd1bdbee8bfd22d0a9081f893355a250a0e1a530
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache8setColorERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95870 */ cbz x4, #0x95880;
    /* 0x95874 */ mov x0, x2;
    /* 0x95878 */ mov x1, x4;
    /* 0x9587c */ b #0xa4840;
    /* 0x95880 */ adrp x2, #0x6d000;
    /* 0x95884 */ add x2, x2, #0xcd3;
    /* 0x95888 */ mov w1, #7;
    /* 0x9588c */ b #0x882c8;
}
