// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x919cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setLeftToRight
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x919cc | Size: 16 bytes | SHA256: 8ee3c041d2217145eb7956a848d4e75e1042cf243da7613cddd83fef5252437a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14setLeftToRightEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setLeftToRight(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x919cc */ tst w4, #0xff;
    /* 0x919d0 */ mov x0, x2;
    /* 0x919d4 */ cset w1, ne;
    /* 0x919d8 */ b #0xa2960;
}
