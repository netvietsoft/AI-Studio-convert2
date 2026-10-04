// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f964
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1getEnableGradientBG
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f964 | Size: 28 bytes | SHA256: beee73e1d1f02dbbc24a6d9c8ab39bb787e391ca4d3a69fa9c63139d80ced68b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321ActiveWordBgInterface19getEnableGradientBGEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1getEnableGradientBG(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f964 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f968 */ mov x29, sp;
    /* 0x8f96c */ mov x0, x2;
    _ZNK8mtlabar321ActiveWordBgInterface19getEnableGradientBGEv();
    /* 0x8f974 */ and w0, w0, #1;
    /* 0x8f978 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
