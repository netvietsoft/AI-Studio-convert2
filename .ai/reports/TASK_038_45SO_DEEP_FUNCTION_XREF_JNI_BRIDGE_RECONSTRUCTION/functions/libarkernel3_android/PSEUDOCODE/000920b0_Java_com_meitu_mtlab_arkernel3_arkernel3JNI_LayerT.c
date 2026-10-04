// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x920b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableFlip
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x920b0 | Size: 16 bytes | SHA256: 6d4fe757a0fa4145380760bed94d05e910ce4b44d420bae91c97c84a713cfdd2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction13setEnableFlipEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableFlip(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x920b0 */ tst w4, #0xff;
    /* 0x920b4 */ mov x0, x2;
    /* 0x920b8 */ cset w1, ne;
    /* 0x920bc */ b #0xa2d90;
}
