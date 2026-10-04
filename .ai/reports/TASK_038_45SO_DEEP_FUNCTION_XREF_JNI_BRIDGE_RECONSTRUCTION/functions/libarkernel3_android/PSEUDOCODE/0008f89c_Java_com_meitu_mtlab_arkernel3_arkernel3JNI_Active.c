// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f89c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f89c | Size: 16 bytes | SHA256: 0ec785a7361528341c217284249fa2439012f0d85f19beb346996d8f12fecd22
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321ActiveWordBgInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f89c */ tst w4, #0xff;
    /* 0x8f8a0 */ mov x0, x2;
    /* 0x8f8a4 */ cset w1, ne;
    /* 0x8f8a8 */ b #0xa22b0;
}
