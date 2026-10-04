// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x918c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsBold
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x918c0 | Size: 28 bytes | SHA256: c019da7d77cabd2b8b01839f2e143c8e5a79a67df1bf03006c7f58f5ba326e54
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9getIsBoldEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsBold(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x918c0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x918c4 */ mov x29, sp;
    /* 0x918c8 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction9getIsBoldEv();
    /* 0x918d0 */ and w0, w0, #1;
    /* 0x918d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
