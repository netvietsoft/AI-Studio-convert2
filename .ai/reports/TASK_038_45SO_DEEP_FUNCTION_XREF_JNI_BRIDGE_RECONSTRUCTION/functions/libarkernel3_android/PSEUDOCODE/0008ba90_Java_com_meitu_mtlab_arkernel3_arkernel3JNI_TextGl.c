// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ba90
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ba90 | Size: 28 bytes | SHA256: 66b3b5e1d27a048c7c6596dc03c70c0453b31014ba09afffafe284f24427571e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextGlowConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ba90 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ba94 */ mov x29, sp;
    /* 0x8ba98 */ mov x0, x2;
    _ZNK8mtlabar321TextGlowConfiguration11getEditableEv();
    /* 0x8baa0 */ and w0, w0, #1;
    /* 0x8baa4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
