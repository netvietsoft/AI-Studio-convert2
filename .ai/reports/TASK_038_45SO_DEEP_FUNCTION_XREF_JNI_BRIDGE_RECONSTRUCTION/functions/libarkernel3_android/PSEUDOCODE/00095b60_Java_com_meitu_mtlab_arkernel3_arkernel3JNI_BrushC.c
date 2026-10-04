// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95b60
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords0
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95b60 | Size: 32 bytes | SHA256: d18a49bf7ab0e72ee52704f0d2019b33832cd61eb5e4e572b594113cda6e59aa
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache13setTexCoords0ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setTexCoords0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95b60 */ cbz x4, #0x95b70;
    /* 0x95b64 */ mov x0, x2;
    /* 0x95b68 */ mov x1, x4;
    /* 0x95b6c */ b #0xa4a00;
    /* 0x95b70 */ adrp x2, #0x6e000;
    /* 0x95b74 */ add x2, x2, #0x665;
    /* 0x95b78 */ mov w1, #7;
    /* 0x95b7c */ b #0x882c8;
}
