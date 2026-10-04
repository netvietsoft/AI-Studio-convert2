// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bf50
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bf50 | Size: 28 bytes | SHA256: be52774cbcbbd5bef39a84e3c4d7dfd63020f11b05f06ee4de9f4b8b24945feb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextStrokeConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bf50 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8bf54 */ mov x29, sp;
    /* 0x8bf58 */ mov x0, x2;
    _ZNK8mtlabar323TextStrokeConfiguration9getEnableEv();
    /* 0x8bf60 */ and w0, w0, #1;
    /* 0x8bf64 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
