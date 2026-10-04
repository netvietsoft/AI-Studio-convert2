// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x919b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getLeftToRight
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x919b0 | Size: 28 bytes | SHA256: 4ef5a178f463ac9d981bbc5336a39e2f9ff98b6d350157e386674788bb8ef558
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14getLeftToRightEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getLeftToRight(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x919b0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x919b4 */ mov x29, sp;
    /* 0x919b8 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction14getLeftToRightEv();
    /* 0x919c0 */ and w0, w0, #1;
    /* 0x919c4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
