// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x950c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimManualLine_1strat_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x950c4 | Size: 12 bytes | SHA256: 7b3d93824fb7383236a7fbe20bc6c753df316fdf0468bd55ac8c5f27c07f7773
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimManualLine_1strat_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x950c4 */ cbz x2, #0x950cc;
    /* 0x950c8 */ str s0, [x2];
    return x0;
}
