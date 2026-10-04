// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91884
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsStaticShow
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91884 | Size: 16 bytes | SHA256: 3b627ae848b9dc8095bc6f91cba432922c7b9ee0a300129cf9a0a2d2e341be97
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction15setIsStaticShowEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsStaticShow(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91884 */ tst w4, #0xff;
    /* 0x91888 */ mov x0, x2;
    /* 0x9188c */ cset w1, ne;
    /* 0x91890 */ b #0xa2860;
}
