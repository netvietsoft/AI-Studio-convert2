// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95bd8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setMixColors
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95bd8 | Size: 32 bytes | SHA256: 24d772d638e289ec704b5e2627898bed899ef13afbb4975f5158f14f742c8b4c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache12setMixColorsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setMixColors(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95bd8 */ cbz x4, #0x95be8;
    /* 0x95bdc */ mov x0, x2;
    /* 0x95be0 */ mov x1, x4;
    /* 0x95be4 */ b #0xa4a60;
    /* 0x95be8 */ adrp x2, #0x6e000;
    /* 0x95bec */ add x2, x2, #0x665;
    /* 0x95bf0 */ mov w1, #7;
    /* 0x95bf4 */ b #0x882c8;
}
