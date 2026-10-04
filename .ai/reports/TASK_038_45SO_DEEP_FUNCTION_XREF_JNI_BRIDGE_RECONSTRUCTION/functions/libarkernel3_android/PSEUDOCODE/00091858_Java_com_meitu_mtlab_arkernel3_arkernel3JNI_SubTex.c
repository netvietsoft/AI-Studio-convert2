// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91858
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsColorORGBAWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91858 | Size: 16 bytes | SHA256: 67ed7d6c483f288d1be2183cb82f616cad94e35b8f45311f0379489db91698ce
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction19setIsColorORGBAWorkEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsColorORGBAWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91858 */ tst w4, #0xff;
    /* 0x9185c */ mov x0, x2;
    /* 0x91860 */ cset w1, ne;
    /* 0x91864 */ b #0xa2840;
}
