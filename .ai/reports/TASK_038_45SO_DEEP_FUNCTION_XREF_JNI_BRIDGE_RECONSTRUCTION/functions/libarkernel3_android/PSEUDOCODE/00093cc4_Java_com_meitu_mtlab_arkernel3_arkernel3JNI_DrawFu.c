// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93cc4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1destroyInstance
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93cc4 | Size: 20 bytes | SHA256: 2413d125dc9e879825178d5b7545a2d4681b1a117274d13cc5a0f2faa269f470
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1destroyInstance(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x93cc4 */ ldr x8, [x2];
    /* 0x93cc8 */ mov x0, x2;
    /* 0x93ccc */ mov x1, x4;
    /* 0x93cd0 */ ldr x2, [x8, #0x18];
    /* 0x93cd4 */ br x2;
}
