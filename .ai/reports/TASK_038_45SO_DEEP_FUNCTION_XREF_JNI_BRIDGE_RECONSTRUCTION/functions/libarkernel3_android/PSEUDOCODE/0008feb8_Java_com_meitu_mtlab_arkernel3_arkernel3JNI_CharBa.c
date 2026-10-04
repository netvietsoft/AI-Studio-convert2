// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8feb8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8feb8 | Size: 28 bytes | SHA256: 3e0e3ae27f14d971516d30962b89400e5f8327d7f39250c80dad56d07fbf34e4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323CharBackgroundInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8feb8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8febc */ mov x29, sp;
    /* 0x8fec0 */ mov x0, x2;
    _ZNK8mtlabar323CharBackgroundInterface9getEnableEv();
    /* 0x8fec8 */ and w0, w0, #1;
    /* 0x8fecc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
