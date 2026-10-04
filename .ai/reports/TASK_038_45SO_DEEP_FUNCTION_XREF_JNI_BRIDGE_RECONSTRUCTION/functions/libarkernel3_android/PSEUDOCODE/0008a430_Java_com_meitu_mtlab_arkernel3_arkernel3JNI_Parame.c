// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a430
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1path_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a430 | Size: 32 bytes | SHA256: c21cecae527726e8c7fb6e7457bc1749a7b5f42d51abf091e8ad72f8ffb543a4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1path_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8a430 */ ldrb w8, [x2, #0x80];
    /* 0x8a434 */ ldr x10, [x0];
    /* 0x8a438 */ add x11, x2, #0x81;
    /* 0x8a43c */ ldr x9, [x2, #0x90];
    /* 0x8a440 */ tst w8, #1;
    /* 0x8a444 */ ldr x2, [x10, #0x538];
    /* 0x8a448 */ csel x1, x11, x9, eq;
    /* 0x8a44c */ br x2;
}
