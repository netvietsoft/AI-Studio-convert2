// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c780
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1leftTop_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c780 | Size: 16 bytes | SHA256: f61b63ef11b4c4d8db40496db14796c9aed50b4505df686c99900f18ec4c7655
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1leftTop_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c780 */ cbz x2, #0x8c78c;
    /* 0x8c784 */ ldr x8, [x4];
    /* 0x8c788 */ str x8, [x2, #0x18];
    return x0;
}
