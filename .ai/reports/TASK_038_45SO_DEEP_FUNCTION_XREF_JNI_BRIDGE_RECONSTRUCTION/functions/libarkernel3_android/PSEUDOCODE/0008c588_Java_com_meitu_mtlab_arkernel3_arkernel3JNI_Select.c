// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c588
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectHighlightConfig_1length_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c588 | Size: 12 bytes | SHA256: 448533a920689e6b558fbde9d61bd4c61a6c2653fd04452cccea2516187bdbe6
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectHighlightConfig_1length_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c588 */ cbz x2, #0x8c590;
    /* 0x8c58c */ str w4, [x2, #0x1c];
    return x0;
}
