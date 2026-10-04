// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8cdcc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectAnimationConfig_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8cdcc | Size: 20 bytes | SHA256: 1c968d157951a5fa2751d3141e31e749787f4f81064a7487d963b977d04800bb
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectAnimationConfig_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8cdcc */ ldr x8, [x2, #0x10];
    /* 0x8cdd0 */ ldr x9, [x2];
    /* 0x8cdd4 */ sub x8, x8, x9;
    /* 0x8cdd8 */ asr x0, x8, #5;
    return x0;
}
