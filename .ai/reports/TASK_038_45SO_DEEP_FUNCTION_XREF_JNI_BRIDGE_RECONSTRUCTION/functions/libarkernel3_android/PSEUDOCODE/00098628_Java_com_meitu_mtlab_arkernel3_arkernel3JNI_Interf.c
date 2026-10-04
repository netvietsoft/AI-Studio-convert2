// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98628
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onInternalTimerCallback
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98628 | Size: 16 bytes | SHA256: 688ebaaddd2ccd623d5e4037898132395a769ce5932c148ff8c1392ef351b94d
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onInternalTimerCallback(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x98628 */ ldr x8, [x2];
    /* 0x9862c */ mov x0, x2;
    /* 0x98630 */ ldr x1, [x8, #0x10];
    /* 0x98634 */ br x1;
}
