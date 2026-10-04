// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a280
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1str_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a280 | Size: 32 bytes | SHA256: 0ec8d413fda14365c4b0836efb3f9d376116e2da0d78c36e526068c2c00688e4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1str_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8a280 */ ldrb w8, [x2, #0x30];
    /* 0x8a284 */ ldr x10, [x0];
    /* 0x8a288 */ add x11, x2, #0x31;
    /* 0x8a28c */ ldr x9, [x2, #0x40];
    /* 0x8a290 */ tst w8, #1;
    /* 0x8a294 */ ldr x2, [x10, #0x538];
    /* 0x8a298 */ csel x1, x11, x9, eq;
    /* 0x8a29c */ br x2;
}
