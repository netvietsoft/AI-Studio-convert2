// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92b04
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1setReverse
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92b04 | Size: 16 bytes | SHA256: 57bf621bdd16338772ea1aceaab86ebe3ca30d649297a675c9e19b071f1ddfed
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerMaskInteraction10setReverseEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1setReverse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92b04 */ tst w4, #0xff;
    /* 0x92b08 */ mov x0, x2;
    /* 0x92b0c */ cset w1, ne;
    /* 0x92b10 */ b #0xa30b0;
}
