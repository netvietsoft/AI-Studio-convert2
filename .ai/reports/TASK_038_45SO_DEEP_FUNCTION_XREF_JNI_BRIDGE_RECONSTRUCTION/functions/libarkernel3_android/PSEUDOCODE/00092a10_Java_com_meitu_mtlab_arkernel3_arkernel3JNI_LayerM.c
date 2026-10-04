// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92a10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1valid
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92a10 | Size: 28 bytes | SHA256: daf2de38a7441989190296ebe1d35eb35dc60da415d3c69fe6f39f357a1a9a98
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerMaskInteraction5validEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1valid(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92a10 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92a14 */ mov x29, sp;
    /* 0x92a18 */ mov x0, x2;
    _ZN8mtlabar320LayerMaskInteraction5validEv();
    /* 0x92a20 */ and w0, w0, #1;
    /* 0x92a24 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
