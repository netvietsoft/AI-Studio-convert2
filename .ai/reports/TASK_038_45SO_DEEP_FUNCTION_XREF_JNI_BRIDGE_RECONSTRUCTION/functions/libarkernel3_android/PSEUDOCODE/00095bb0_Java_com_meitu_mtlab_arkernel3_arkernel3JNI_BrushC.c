// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95bb0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords2
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95bb0 | Size: 32 bytes | SHA256: 7a275c5fb3a504b1be54714125a477a352acd918a4c1611d48f8943def2e39ed
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache13setTexCoords2ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords2(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95bb0 */ cbz x4, #0x95bc0;
    /* 0x95bb4 */ mov x0, x2;
    /* 0x95bb8 */ mov x1, x4;
    /* 0x95bbc */ b #0xa4a40;
    /* 0x95bc0 */ adrp x2, #0x6e000;
    /* 0x95bc4 */ add x2, x2, #0x665;
    /* 0x95bc8 */ mov w1, #7;
    /* 0x95bcc */ b #0x882c8;
}
