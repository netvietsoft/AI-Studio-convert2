// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x918b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsMultiStrokes
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x918b0 | Size: 16 bytes | SHA256: 7dcd6ea9cde8da16b6b1ed01710f9c65c09218538f735b988d3b139210429694
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction17setIsMultiStrokesEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setIsMultiStrokes(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x918b0 */ tst w4, #0xff;
    /* 0x918b4 */ mov x0, x2;
    /* 0x918b8 */ cset w1, ne;
    /* 0x918bc */ b #0xa2880;
}
