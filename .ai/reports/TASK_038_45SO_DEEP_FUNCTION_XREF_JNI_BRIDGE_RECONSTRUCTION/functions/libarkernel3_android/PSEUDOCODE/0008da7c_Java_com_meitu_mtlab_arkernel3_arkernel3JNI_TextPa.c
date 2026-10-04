// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8da7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setEnableBend
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8da7c | Size: 16 bytes | SHA256: 8e7fbab4a1f4ad7eb85cce976a73d4b7953aeba6653485c639bd97a6f3f5585c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextPathConfiguration13setEnableBendEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setEnableBend(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8da7c */ tst w4, #0xff;
    /* 0x8da80 */ mov x0, x2;
    /* 0x8da84 */ cset w1, ne;
    /* 0x8da88 */ b #0xa1110;
}
