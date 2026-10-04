// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8be0c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8be0c | Size: 16 bytes | SHA256: 1cc6cec2140002cedb31624122709ea4910d7499bd812212fb5b5d69ee42cae1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextShadowConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8be0c */ tst w4, #0xff;
    /* 0x8be10 */ mov x0, x2;
    /* 0x8be14 */ cset w1, ne;
    /* 0x8be18 */ b #0xa0cd0;
}
