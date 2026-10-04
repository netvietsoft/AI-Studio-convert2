// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94150
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireShoulderData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94150 | Size: 28 bytes | SHA256: 954dad9900955e6b81bd16d2d28c9245a14a07c8f71f3f52aad3a2be04fabd7e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire19requireShoulderDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireShoulderData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94150 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94154 */ mov x29, sp;
    /* 0x94158 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire19requireShoulderDataEv();
    /* 0x94160 */ and w0, w0, #1;
    /* 0x94164 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
