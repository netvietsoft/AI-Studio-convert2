// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9183c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsColorORGBAWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9183c | Size: 28 bytes | SHA256: 4883faa2f62942dfbbcbdf4e732c9f2f197a4673d5925d072a0bf2efe2b90f56
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction19getIsColorORGBAWorkEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsColorORGBAWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9183c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91840 */ mov x29, sp;
    /* 0x91844 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction19getIsColorORGBAWorkEv();
    /* 0x9184c */ and w0, w0, #1;
    /* 0x91850 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
