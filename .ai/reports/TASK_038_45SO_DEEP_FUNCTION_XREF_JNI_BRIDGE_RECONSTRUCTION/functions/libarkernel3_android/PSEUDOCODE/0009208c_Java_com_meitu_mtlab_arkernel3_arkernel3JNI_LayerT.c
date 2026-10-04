// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9208c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableGlobalColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9208c | Size: 28 bytes | SHA256: e9139997473780e37a2f5730cf18138aabf88bfa8de61ae064b1b44ab1972949
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction20getEnableGlobalColorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableGlobalColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9208c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92090 */ mov x29, sp;
    /* 0x92094 */ mov x0, x2;
    _ZN8mtlabar320LayerTextInteraction20getEnableGlobalColorEv();
    /* 0x9209c */ and w0, w0, #1;
    /* 0x920a0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
