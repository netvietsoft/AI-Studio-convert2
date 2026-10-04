// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97ba0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1setPartControlVisible
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97ba0 | Size: 16 bytes | SHA256: ba7b9057110c42277a84e121dc2ad797487ccc67fc0b84b8259f61c574b4d437
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl21setPartControlVisibleEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1setPartControlVisible(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x97ba0 */ tst w4, #0xff;
    /* 0x97ba4 */ mov x0, x2;
    /* 0x97ba8 */ cset w1, ne;
    /* 0x97bac */ b #0xa52e0;
}
