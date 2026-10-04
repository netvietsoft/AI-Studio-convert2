// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8edd8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1isPaddingZero
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8edd8 | Size: 28 bytes | SHA256: 895dec76997d03fb8328456e3594bfbecc84963a76f2950ac7847f6f70b9d833
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326IconSequenceStyleInterface13isPaddingZeroEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1isPaddingZero(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8edd8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8eddc */ mov x29, sp;
    /* 0x8ede0 */ mov x0, x2;
    _ZNK8mtlabar326IconSequenceStyleInterface13isPaddingZeroEv();
    /* 0x8ede8 */ and w0, w0, #1;
    /* 0x8edec */ ldp x29, x30, [sp], #0x10;
    return x0;
}
