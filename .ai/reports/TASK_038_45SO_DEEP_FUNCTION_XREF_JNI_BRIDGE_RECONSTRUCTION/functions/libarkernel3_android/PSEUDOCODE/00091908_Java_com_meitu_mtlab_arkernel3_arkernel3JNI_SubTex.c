// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91908
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsItalic
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91908 | Size: 16 bytes | SHA256: 61ebd5bc1aa34fea39df6951d2ce86ccdb6cb0200e095e35af27a3363f8e124a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction11setIsItalicEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsItalic(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91908 */ tst w4, #0xff;
    /* 0x9190c */ mov x0, x2;
    /* 0x91910 */ cset w1, ne;
    /* 0x91914 */ b #0xa28c0;
}
