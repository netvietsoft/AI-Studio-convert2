// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93148
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setMirror
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93148 | Size: 16 bytes | SHA256: d3987f91b6db482b8ea49aa85355883be82aefd974144cfd910d20929eb1741e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerTransformInteraction9setMirrorEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setMirror(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x93148 */ tst w4, #0xff;
    /* 0x9314c */ mov x0, x2;
    /* 0x93150 */ cset w1, ne;
    /* 0x93154 */ b #0xa3580;
}
