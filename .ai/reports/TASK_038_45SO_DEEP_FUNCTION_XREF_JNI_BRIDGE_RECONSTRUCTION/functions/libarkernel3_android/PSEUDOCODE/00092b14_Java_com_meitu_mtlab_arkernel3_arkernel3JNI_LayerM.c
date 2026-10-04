// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92b14
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1getReverse
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92b14 | Size: 28 bytes | SHA256: 99e8895123ab01b7d976a5b097834f82a9fef55c97976ccf01f50ea40d977f5f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerMaskInteraction10getReverseEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1getReverse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92b14 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92b18 */ mov x29, sp;
    /* 0x92b1c */ mov x0, x2;
    _ZN8mtlabar320LayerMaskInteraction10getReverseEv();
    /* 0x92b24 */ and w0, w0, #1;
    /* 0x92b28 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
