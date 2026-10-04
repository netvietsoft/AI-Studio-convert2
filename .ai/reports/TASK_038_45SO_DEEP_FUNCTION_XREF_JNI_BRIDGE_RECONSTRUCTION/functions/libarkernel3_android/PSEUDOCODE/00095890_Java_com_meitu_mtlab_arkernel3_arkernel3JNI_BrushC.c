// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95890
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1getPenMode
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95890 | Size: 64 bytes | SHA256: f2ac6cf241c0de0b624d8071852c130c0a7d2e8d5f7030e86e9aba53e02696d6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310BrushCache10getPenModeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1getPenMode(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x95890 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x95894 */ str x19, [sp, #0x10];
    /* 0x95898 */ mov x29, sp;
    /* 0x9589c */ mov x19, x0;
    /* 0x958a0 */ mov x0, x2;
    _ZNK8mtlabar310BrushCache10getPenModeEv();
    /* 0x958a8 */ ldr x8, [x19];
    /* 0x958ac */ ldrb w9, [x0];
    /* 0x958b0 */ ldr x10, [x0, #0x10];
    /* 0x958b4 */ tst w9, #1;
    /* 0x958b8 */ ldr x2, [x8, #0x538];
}
