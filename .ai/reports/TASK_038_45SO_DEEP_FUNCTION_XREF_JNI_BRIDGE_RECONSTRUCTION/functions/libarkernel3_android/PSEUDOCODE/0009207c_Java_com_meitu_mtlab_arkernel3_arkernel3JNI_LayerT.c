// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9207c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableGlobalColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9207c | Size: 16 bytes | SHA256: a0d1d9114b791fe7eb85e3379cbbb65e06f0a99564ef778d7b1c1283861d0bb6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction20setEnableGlobalColorEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableGlobalColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9207c */ tst w4, #0xff;
    /* 0x92080 */ mov x0, x2;
    /* 0x92084 */ cset w1, ne;
    /* 0x92088 */ b #0xa2d60;
}
