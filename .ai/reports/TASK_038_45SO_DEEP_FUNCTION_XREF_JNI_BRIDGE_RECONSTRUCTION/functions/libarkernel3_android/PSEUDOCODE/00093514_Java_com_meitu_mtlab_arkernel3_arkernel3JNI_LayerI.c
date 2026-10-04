// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93514
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getDesignedForceSelectable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93514 | Size: 28 bytes | SHA256: 333eca2f7be4fc3b0f958c5b9b22cc9046a40423cc641d9ea309224954c01a42
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction26getDesignedForceSelectableEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getDesignedForceSelectable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93514 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93518 */ mov x29, sp;
    /* 0x9351c */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction26getDesignedForceSelectableEv();
    /* 0x93524 */ and w0, w0, #1;
    /* 0x93528 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
