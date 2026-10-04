// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91ba0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsVisible
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91ba0 | Size: 16 bytes | SHA256: f3eeaf48ccc3c4666c3df09eb4d6a6eeea3ad3fcb0220a05afd70103ef61b9bc
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12setIsVisibleEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsVisible(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91ba0 */ tst w4, #0xff;
    /* 0x91ba4 */ mov x0, x2;
    /* 0x91ba8 */ cset w1, ne;
    /* 0x91bac */ b #0xa2ae0;
}
