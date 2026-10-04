// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91918
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsUnderline
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91918 | Size: 28 bytes | SHA256: b26429c8c46404a75386726522f1ac115d66bd2ee350641fc7efd5e0c9541bd7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14getIsUnderlineEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsUnderline(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91918 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9191c */ mov x29, sp;
    /* 0x91920 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction14getIsUnderlineEv();
    /* 0x91928 */ and w0, w0, #1;
    /* 0x9192c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
