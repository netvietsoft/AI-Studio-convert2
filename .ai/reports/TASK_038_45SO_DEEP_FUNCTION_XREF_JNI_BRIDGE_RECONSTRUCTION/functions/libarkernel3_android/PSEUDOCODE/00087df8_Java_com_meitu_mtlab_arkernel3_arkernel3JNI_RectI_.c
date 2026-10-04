// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87df8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1width
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87df8 | Size: 16 bytes | SHA256: fba5ac5ba6c50234e1e64e88769451d994d8d57137ae1d54ac29830091e8cf41
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_RectI_1width(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x87df8 */ ldr w8, [x2, #8];
    /* 0x87dfc */ ldr w9, [x2];
    /* 0x87e00 */ sub w0, w8, w9;
    return x0;
}
