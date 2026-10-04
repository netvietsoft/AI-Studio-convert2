// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c29c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1positionOffset_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c29c | Size: 12 bytes | SHA256: 308e56d5996fe3a48335e450948678dbabf06ebedf593f67827cec0b36d84f67
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1positionOffset_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c29c */ cbz x2, #0x8c2a4;
    /* 0x8c2a0 */ str s0, [x2, #0x2c];
    return x0;
}
