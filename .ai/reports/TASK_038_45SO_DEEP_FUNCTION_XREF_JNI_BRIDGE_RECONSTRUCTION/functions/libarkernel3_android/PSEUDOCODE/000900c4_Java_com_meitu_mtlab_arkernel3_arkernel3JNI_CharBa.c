// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x900c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getCharBackgroundPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x900c4 | Size: 64 bytes | SHA256: c431d5c90217b9d65e38288a285968d794e993dad6907cdd3a46765044e463ab
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323CharBackgroundInterface21getCharBackgroundPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1getCharBackgroundPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x900c4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x900c8 */ str x19, [sp, #0x10];
    /* 0x900cc */ mov x29, sp;
    /* 0x900d0 */ mov x19, x0;
    /* 0x900d4 */ mov x0, x2;
    _ZNK8mtlabar323CharBackgroundInterface21getCharBackgroundPathEv();
    /* 0x900dc */ ldr x8, [x19];
    /* 0x900e0 */ ldrb w9, [x0];
    /* 0x900e4 */ ldr x10, [x0, #0x10];
    /* 0x900e8 */ tst w9, #1;
    /* 0x900ec */ ldr x2, [x8, #0x538];
}
