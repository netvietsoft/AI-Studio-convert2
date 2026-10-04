// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x934c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getEnableSelected
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x934c0 | Size: 28 bytes | SHA256: 05a595ddd26d83570ebd782ab8fe8fa4b97c47ad411e1e5085c70b343cdabcd2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction17getEnableSelectedEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getEnableSelected(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x934c0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x934c4 */ mov x29, sp;
    /* 0x934c8 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction17getEnableSelectedEv();
    /* 0x934d0 */ and w0, w0, #1;
    /* 0x934d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
