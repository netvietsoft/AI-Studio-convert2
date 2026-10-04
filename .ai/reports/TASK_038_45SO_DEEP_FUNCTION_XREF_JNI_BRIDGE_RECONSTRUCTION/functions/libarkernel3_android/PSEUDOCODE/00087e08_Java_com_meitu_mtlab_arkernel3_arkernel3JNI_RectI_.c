// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87e08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1height
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87e08 | Size: 16 bytes | SHA256: 5229ac995d4d717d2e5aec18cf545801615d59d4d6e56f120bb619cbc8dc63c3
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1height(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x87e08 */ ldr w8, [x2, #0xc];
    /* 0x87e0c */ ldr w9, [x2, #4];
    /* 0x87e10 */ sub w0, w8, w9;
    return x0;
}
