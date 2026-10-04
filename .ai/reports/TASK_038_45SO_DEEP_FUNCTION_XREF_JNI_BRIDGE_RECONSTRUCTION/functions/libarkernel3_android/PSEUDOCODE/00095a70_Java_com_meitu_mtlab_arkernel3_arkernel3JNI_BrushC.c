// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95a70
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setInitDir
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95a70 | Size: 32 bytes | SHA256: ec4f35d535c181ea67a3d01e39c84fef7acf820c81bff68903a93e121799b1b8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache10setInitDirERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setInitDir(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95a70 */ cbz x4, #0x95a80;
    /* 0x95a74 */ mov x0, x2;
    /* 0x95a78 */ mov x1, x4;
    /* 0x95a7c */ b #0xa4940;
    /* 0x95a80 */ adrp x2, #0x6d000;
    /* 0x95a84 */ add x2, x2, #0xcd3;
    /* 0x95a88 */ mov w1, #7;
    /* 0x95a8c */ b #0x882c8;
}
