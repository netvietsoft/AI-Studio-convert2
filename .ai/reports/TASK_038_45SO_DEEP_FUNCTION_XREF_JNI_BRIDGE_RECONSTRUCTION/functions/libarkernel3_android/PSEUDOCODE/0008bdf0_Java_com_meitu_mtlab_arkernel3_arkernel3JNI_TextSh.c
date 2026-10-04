// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bdf0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bdf0 | Size: 28 bytes | SHA256: aa1cc48bee00186137a854c6a3fc6b1807b57ef2e34c43d2cc9027f3f72cc837
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextShadowConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bdf0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8bdf4 */ mov x29, sp;
    /* 0x8bdf8 */ mov x0, x2;
    _ZNK8mtlabar323TextShadowConfiguration11getEditableEv();
    /* 0x8be00 */ and w0, w0, #1;
    /* 0x8be04 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
