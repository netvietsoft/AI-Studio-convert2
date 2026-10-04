// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c23c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1perpendicular_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c23c | Size: 20 bytes | SHA256: 2731ee49c8cada502484954d2b7fb016aa999c1ba5a38e4efe3dfa0094fa3a2d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1perpendicular_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c23c */ cbz x2, #0x8c24c;
    /* 0x8c240 */ tst w4, #0xff;
    /* 0x8c244 */ cset w8, ne;
    /* 0x8c248 */ strb w8, [x2, #0x20];
    return x0;
}
