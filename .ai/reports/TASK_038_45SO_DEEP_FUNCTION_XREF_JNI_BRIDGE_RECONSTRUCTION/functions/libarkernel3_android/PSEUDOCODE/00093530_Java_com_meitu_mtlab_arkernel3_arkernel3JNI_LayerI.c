// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93530
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getIsEnableDepth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93530 | Size: 28 bytes | SHA256: f03a7dff774aaf74539f81ab3a39bf9c8e8820c82221d4af07caf097e713402e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction16getIsEnableDepthEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getIsEnableDepth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93530 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93534 */ mov x29, sp;
    /* 0x93538 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction16getIsEnableDepthEv();
    /* 0x93540 */ and w0, w0, #1;
    /* 0x93544 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
