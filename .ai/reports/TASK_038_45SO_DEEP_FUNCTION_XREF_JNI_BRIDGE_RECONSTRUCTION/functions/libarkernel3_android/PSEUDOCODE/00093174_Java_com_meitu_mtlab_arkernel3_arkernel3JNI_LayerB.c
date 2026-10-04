// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93174
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1setAreaLimit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93174 | Size: 16 bytes | SHA256: 1627907be6b7b62950c91dc63898ad0db88f9732b7a75e72fe7ab3e0f9567943
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction12setAreaLimitEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1setAreaLimit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x93174 */ tst w4, #0xff;
    /* 0x93178 */ mov x0, x2;
    /* 0x9317c */ cset w1, ne;
    /* 0x93180 */ b #0xa35a0;
}
