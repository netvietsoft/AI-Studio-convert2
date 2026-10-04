// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9329c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getEnableTextBoxInteraction
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9329c | Size: 28 bytes | SHA256: 29f4433cea2fa2bfac84a5078241bff8e55dce0ab14565a2984370f932570b95
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction27getEnableTextBoxInteractionEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getEnableTextBoxInteraction(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9329c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x932a0 */ mov x29, sp;
    /* 0x932a4 */ mov x0, x2;
    _ZN8mtlabar322LayerBorderInteraction27getEnableTextBoxInteractionEv();
    /* 0x932ac */ and w0, w0, #1;
    /* 0x932b0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
