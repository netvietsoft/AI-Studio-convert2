// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x981a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1setApply
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x981a0 | Size: 16 bytes | SHA256: 1c79dacc4131313b6049362ac7fffc2f25be7e1d3a64675dc06649c5036a8653
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData8setApplyEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1setApply(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x981a0 */ tst w4, #0xff;
    /* 0x981a4 */ mov x0, x2;
    /* 0x981a8 */ cset w1, ne;
    /* 0x981ac */ b #0xa5510;
}
