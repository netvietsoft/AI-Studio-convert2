// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92014
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setGlobalColorValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92014 | Size: 32 bytes | SHA256: 83a7d078d7f7af19dc294d2d9ea2ab7eb9baf4a0eb0b7bdd9b39631cdaab629e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction19setGlobalColorValueERKNS_5ColorE
// Strings referenced:
//   "mtlabar3::Color const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setGlobalColorValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92014 */ cbz x4, #0x92024;
    /* 0x92018 */ mov x0, x2;
    /* 0x9201c */ mov x1, x4;
    /* 0x92020 */ b #0xa2d40;
    /* 0x92024 */ adrp x2, #0x6e000;
    /* 0x92028 */ add x2, x2, #0x32c;
    /* 0x9202c */ mov w1, #7;
    /* 0x92030 */ b #0x882c8;
}
