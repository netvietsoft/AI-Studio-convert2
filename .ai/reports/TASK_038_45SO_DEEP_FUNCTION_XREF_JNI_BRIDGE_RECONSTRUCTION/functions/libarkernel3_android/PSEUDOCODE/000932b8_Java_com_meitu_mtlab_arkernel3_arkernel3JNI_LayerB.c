// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x932b8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1setEnableTextBoxInteraction
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x932b8 | Size: 16 bytes | SHA256: c44e84d58d11771656dcbe85dc9f5925a2476bcf7d9f5e3a86af214aebe9f02c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction27setEnableTextBoxInteractionEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1setEnableTextBoxInteraction(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x932b8 */ tst w4, #0xff;
    /* 0x932bc */ mov x0, x2;
    /* 0x932c0 */ cset w1, ne;
    /* 0x932c4 */ b #0xa3670;
}
