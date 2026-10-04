// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x930b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setScaleXY
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x930b0 | Size: 32 bytes | SHA256: c8af164acaa5bdf446dee3330c9700bc3580925c3218c9ac3a4c9de05f6cc369
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerTransformInteraction10setScaleXYENS_6Float2E
// Strings referenced:
//   "Attempt to dereference null mtlabar3::Point2F"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setScaleXY(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x930b0 */ cbz x4, #0x930c0;
    /* 0x930b4 */ ldp s0, s1, [x4];
    /* 0x930b8 */ mov x0, x2;
    /* 0x930bc */ b #0xa3530;
    /* 0x930c0 */ adrp x2, #0x6d000;
    /* 0x930c4 */ add x2, x2, #0xd55;
    /* 0x930c8 */ mov w1, #7;
    /* 0x930cc */ b #0x882c8;
}
