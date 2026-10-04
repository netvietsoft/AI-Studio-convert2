// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94770
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireUserDefinedMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94770 | Size: 28 bytes | SHA256: ff779ff9f4593a5f503aeeb2728a2fb73c9ec08df1daf048e1aa08a8faed6126
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireUserDefinedMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireUserDefinedMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94770 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94774 */ mov x29, sp;
    /* 0x94778 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireUserDefinedMaskEv();
    /* 0x94780 */ and w0, w0, #1;
    /* 0x94784 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
