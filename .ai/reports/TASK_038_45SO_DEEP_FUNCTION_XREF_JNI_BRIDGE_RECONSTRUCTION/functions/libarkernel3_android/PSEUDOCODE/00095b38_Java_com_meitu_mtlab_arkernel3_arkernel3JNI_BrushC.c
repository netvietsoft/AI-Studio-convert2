// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95b38
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setPositions
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95b38 | Size: 32 bytes | SHA256: 052ea6715d1690eef4d4bd7f80828c01481e7e6bd6fb685355f20ffa1541aa8c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache12setPositionsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setPositions(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95b38 */ cbz x4, #0x95b48;
    /* 0x95b3c */ mov x0, x2;
    /* 0x95b40 */ mov x1, x4;
    /* 0x95b44 */ b #0xa49e0;
    /* 0x95b48 */ adrp x2, #0x6e000;
    /* 0x95b4c */ add x2, x2, #0x665;
    /* 0x95b50 */ mov w1, #7;
    /* 0x95b54 */ b #0x882c8;
}
