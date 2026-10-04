// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d9e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setPerpendicular
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d9e4 | Size: 16 bytes | SHA256: e82d65e2d5bc42b39b37654f142544e448cc34810c6bcc6a06a023b667d424d3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextPathConfiguration16setPerpendicularEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setPerpendicular(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d9e4 */ tst w4, #0xff;
    /* 0x8d9e8 */ mov x0, x2;
    /* 0x8d9ec */ cset w1, ne;
    /* 0x8d9f0 */ b #0xa1050;
}
