// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c6c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectAnimationConfig_1configPath_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c6c4 | Size: 28 bytes | SHA256: 2000ff82407cecd7afc9230caac505ef98b1c7905e854fbce2cfe6626d3bf7fe
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectAnimationConfig_1configPath_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8c6c4 */ ldrb w8, [x2];
    /* 0x8c6c8 */ ldr x9, [x2, #0x10];
    /* 0x8c6cc */ ldr x10, [x0];
    /* 0x8c6d0 */ tst w8, #1;
    /* 0x8c6d4 */ csinc x1, x9, x2, ne;
    /* 0x8c6d8 */ ldr x2, [x10, #0x538];
    /* 0x8c6dc */ br x2;
}
