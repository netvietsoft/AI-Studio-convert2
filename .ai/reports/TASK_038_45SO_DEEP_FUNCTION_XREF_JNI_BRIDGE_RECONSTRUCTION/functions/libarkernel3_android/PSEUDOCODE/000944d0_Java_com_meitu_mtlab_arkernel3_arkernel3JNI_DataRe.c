// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x944d0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireEyeMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x944d0 | Size: 28 bytes | SHA256: a78ae127cfe0728e0bdc0e4d80ff5db4dcd0516da0af7d1196735fc94c2a404e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire14requireEyeMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireEyeMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x944d0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x944d4 */ mov x29, sp;
    /* 0x944d8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire14requireEyeMaskEv();
    /* 0x944e0 */ and w0, w0, #1;
    /* 0x944e4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
