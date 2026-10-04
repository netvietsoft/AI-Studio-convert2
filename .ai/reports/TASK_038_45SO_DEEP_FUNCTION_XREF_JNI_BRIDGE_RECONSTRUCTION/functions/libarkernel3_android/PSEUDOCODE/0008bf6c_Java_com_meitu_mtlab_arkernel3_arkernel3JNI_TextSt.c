// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bf6c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bf6c | Size: 16 bytes | SHA256: 118f23cbc25d3211cafa5df6486102e0a05edeadd43f0dbc11a63615660ff2cb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextStrokeConfiguration9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8bf6c */ tst w4, #0xff;
    /* 0x8bf70 */ mov x0, x2;
    /* 0x8bf74 */ cset w1, ne;
    /* 0x8bf78 */ b #0xa0da0;
}
