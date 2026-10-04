// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95b88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords1
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95b88 | Size: 32 bytes | SHA256: 10a0e8a6eef469b7231941d89964f8914689d0aa870e4bc2b537f442c55edc71
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache13setTexCoords1ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords1(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95b88 */ cbz x4, #0x95b98;
    /* 0x95b8c */ mov x0, x2;
    /* 0x95b90 */ mov x1, x4;
    /* 0x95b94 */ b #0xa4a20;
    /* 0x95b98 */ adrp x2, #0x6e000;
    /* 0x95b9c */ add x2, x2, #0x665;
    /* 0x95ba0 */ mov w1, #7;
    /* 0x95ba4 */ b #0x882c8;
}
