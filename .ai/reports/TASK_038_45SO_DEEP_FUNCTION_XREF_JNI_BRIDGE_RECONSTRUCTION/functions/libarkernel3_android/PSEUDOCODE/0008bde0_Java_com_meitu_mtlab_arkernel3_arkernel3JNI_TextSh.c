// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bde0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bde0 | Size: 16 bytes | SHA256: 340e76f0fd104efa82a97237b4b70efca4e66a5c39e6a00526edaf72b6caa06f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextShadowConfiguration9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8bde0 */ tst w4, #0xff;
    /* 0x8bde4 */ mov x0, x2;
    /* 0x8bde8 */ cset w1, ne;
    /* 0x8bdec */ b #0xa0cb0;
}
