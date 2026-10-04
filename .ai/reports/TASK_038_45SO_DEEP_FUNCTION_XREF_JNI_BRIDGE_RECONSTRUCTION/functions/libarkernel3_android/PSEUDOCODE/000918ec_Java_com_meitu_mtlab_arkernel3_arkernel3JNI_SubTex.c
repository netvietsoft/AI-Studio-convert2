// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x918ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsItalic
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x918ec | Size: 28 bytes | SHA256: 188ed052fb65df0a5ad85201c12c5823af16a8cab339e79a6c7318c8816e8629
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction11getIsItalicEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsItalic(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x918ec */ stp x29, x30, [sp, #-0x10]!;
    /* 0x918f0 */ mov x29, sp;
    /* 0x918f4 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction11getIsItalicEv();
    /* 0x918fc */ and w0, w0, #1;
    /* 0x91900 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
