// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x918dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsBold
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x918dc | Size: 16 bytes | SHA256: e815a2193d35f97f88abaa26fc3be52487f8ad37d76d727fc86769b819942942
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9setIsBoldEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsBold(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x918dc */ tst w4, #0xff;
    /* 0x918e0 */ mov x0, x2;
    /* 0x918e4 */ cset w1, ne;
    /* 0x918e8 */ b #0xa28a0;
}
