// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9522c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControlInstance_1setEffectIsEffective
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9522c | Size: 16 bytes | SHA256: 6616308f576d22151cc6c6124930cb0b2ce03489112ed5827ba4080faf44fb6b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323BodySlimControlInstance20setEffectIsEffectiveEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControlInstance_1setEffectIsEffective(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9522c */ tst w4, #0xff;
    /* 0x95230 */ mov x0, x2;
    /* 0x95234 */ cset w1, ne;
    /* 0x95238 */ b #0xa4350;
}
