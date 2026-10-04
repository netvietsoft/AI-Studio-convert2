// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91960
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsStrikeThrough
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91960 | Size: 16 bytes | SHA256: 3297ddbacc0acfa8129b5eb7196faaa255715d51ec6813cf6d9a4fb97c075f2f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction18setIsStrikeThroughEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsStrikeThrough(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91960 */ tst w4, #0xff;
    /* 0x91964 */ mov x0, x2;
    /* 0x91968 */ cset w1, ne;
    /* 0x9196c */ b #0xa2900;
}
