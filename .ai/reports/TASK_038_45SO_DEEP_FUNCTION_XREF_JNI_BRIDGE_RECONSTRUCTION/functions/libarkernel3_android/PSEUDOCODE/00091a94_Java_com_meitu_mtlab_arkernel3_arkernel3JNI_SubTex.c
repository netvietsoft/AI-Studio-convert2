// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91a94
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setPinyin
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91a94 | Size: 16 bytes | SHA256: f3ee33a677a778be320aaea7928f2482872aa155b2b2ed1444082c77fee48548
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9setPinyinEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setPinyin(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91a94 */ tst w4, #0xff;
    /* 0x91a98 */ mov x0, x2;
    /* 0x91a9c */ cset w1, ne;
    /* 0x91aa0 */ b #0xa2a40;
}
