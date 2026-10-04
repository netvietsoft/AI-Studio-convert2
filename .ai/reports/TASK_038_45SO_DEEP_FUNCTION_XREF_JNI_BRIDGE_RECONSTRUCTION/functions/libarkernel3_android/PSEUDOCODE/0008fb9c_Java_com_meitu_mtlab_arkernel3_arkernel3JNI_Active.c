// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fb9c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fb9c | Size: 16 bytes | SHA256: 296359247aae721f91aec0a14207a6186f1b3080c2902f6c27e4e121c4a06e8c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324ActiveWordStyleInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8fb9c */ tst w4, #0xff;
    /* 0x8fba0 */ mov x0, x2;
    /* 0x8fba4 */ cset w1, ne;
    /* 0x8fba8 */ b #0xa2510;
}
