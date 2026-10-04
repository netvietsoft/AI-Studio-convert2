// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x919a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setHorizontal
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x919a0 | Size: 16 bytes | SHA256: 3297ddbacc0acfa8129b5eb7196faaa255715d51ec6813cf6d9a4fb97c075f2f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction13setHorizontalEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setHorizontal(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x919a0 */ tst w4, #0xff;
    /* 0x919a4 */ mov x0, x2;
    /* 0x919a8 */ cset w1, ne;
    /* 0x919ac */ b #0xa2940;
}
