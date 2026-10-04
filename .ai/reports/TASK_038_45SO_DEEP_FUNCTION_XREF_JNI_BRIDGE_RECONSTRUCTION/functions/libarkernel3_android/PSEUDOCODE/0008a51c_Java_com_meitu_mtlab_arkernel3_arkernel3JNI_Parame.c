// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a51c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1pad_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a51c | Size: 16 bytes | SHA256: 025a9ee566e989773db7f6524400aa89588849979b8706fdcd17f275e8819801
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1pad_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a51c */ ldr x8, [x0];
    /* 0x8a520 */ add x1, x2, #0xbc;
    /* 0x8a524 */ ldr x3, [x8, #0x538];
    /* 0x8a528 */ br x3;
}
