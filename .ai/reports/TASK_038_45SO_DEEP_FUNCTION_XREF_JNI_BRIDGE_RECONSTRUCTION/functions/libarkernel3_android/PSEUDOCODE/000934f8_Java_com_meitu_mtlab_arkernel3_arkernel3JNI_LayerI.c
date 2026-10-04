// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x934f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getDesignedDraggable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x934f8 | Size: 28 bytes | SHA256: 0af2fbc7a17ede8271db056308fbf7745f1ae58d7ac2f241933455450018f2b1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction20getDesignedDraggableEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getDesignedDraggable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x934f8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x934fc */ mov x29, sp;
    /* 0x93500 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction20getDesignedDraggableEv();
    /* 0x93508 */ and w0, w0, #1;
    /* 0x9350c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
