// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93a64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_delete_1ExternalFunctionCallback
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93a64 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_delete_1ExternalFunctionCallback(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x93a64 */ cbz x2, #0x93a78;
    /* 0x93a68 */ ldr x8, [x2];
    /* 0x93a6c */ mov x0, x2;
    /* 0x93a70 */ ldr x1, [x8, #8];
    /* 0x93a74 */ br x1;
    return x0;
}
