// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x941dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x941dc | Size: 28 bytes | SHA256: cd28b42b25aea1db3661f43c68595cc56e78dae4dd0fa859b0a4df2970168fe4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireBodyMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x941dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x941e0 */ mov x29, sp;
    /* 0x941e4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireBodyMaskEv();
    /* 0x941ec */ and w0, w0, #1;
    /* 0x941f0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
