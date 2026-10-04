// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91bb0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsDisplay
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91bb0 | Size: 28 bytes | SHA256: d94f37694713afeff4a27c76e55b8d977135feba9b15b4c9af79fd2bbfeda34a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12getIsDisplayEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsDisplay(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91bb0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91bb4 */ mov x29, sp;
    /* 0x91bb8 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction12getIsDisplayEv();
    /* 0x91bc0 */ and w0, w0, #1;
    /* 0x91bc4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
