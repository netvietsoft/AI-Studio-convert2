// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91a08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getShrink
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91a08 | Size: 28 bytes | SHA256: b4ce59f225aed563597324e40559858bdca40aed1a88a393a8aa073a9ff9130e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9getShrinkEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getShrink(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91a08 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91a0c */ mov x29, sp;
    /* 0x91a10 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction9getShrinkEv();
    /* 0x91a18 */ and w0, w0, #1;
    /* 0x91a1c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
