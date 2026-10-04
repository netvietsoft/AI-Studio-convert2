// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91894
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsMultiStrokes
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91894 | Size: 28 bytes | SHA256: 63db25fe6118ebd4445ad392e4bbb7b75d343f72cdde6292838e7b6658931220
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction17getIsMultiStrokesEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsMultiStrokes(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91894 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91898 */ mov x29, sp;
    /* 0x9189c */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction17getIsMultiStrokesEv();
    /* 0x918a4 */ and w0, w0, #1;
    /* 0x918a8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
