// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91b84
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsVisible
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91b84 | Size: 28 bytes | SHA256: 88a49e57f5278ccc1a1578c67e4e21d820db3714b45dc8bd7a0ce2350ccbef94
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12getIsVisibleEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsVisible(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91b84 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91b88 */ mov x29, sp;
    /* 0x91b8c */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction12getIsVisibleEv();
    /* 0x91b94 */ and w0, w0, #1;
    /* 0x91b98 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
