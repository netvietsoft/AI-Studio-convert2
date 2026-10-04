// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91a24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setShrink
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91a24 | Size: 16 bytes | SHA256: 4e7ca53409d39c5d662b6d54d8226636209dca83b5268bd30888943b8f56ce60
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9setShrinkEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setShrink(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x91a24 */ tst w4, #0xff;
    /* 0x91a28 */ mov x0, x2;
    /* 0x91a2c */ cset w1, ne;
    /* 0x91a30 */ b #0xa29a0;
}
