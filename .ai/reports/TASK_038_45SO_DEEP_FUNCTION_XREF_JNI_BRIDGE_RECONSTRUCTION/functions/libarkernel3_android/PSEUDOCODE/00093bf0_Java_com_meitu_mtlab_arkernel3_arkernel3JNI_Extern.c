// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93bf0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1onDrawFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93bf0 | Size: 40 bytes | SHA256: 779d82c0babe93879100f64bd169be8c679c6e880c7f6f02d3227a0bfbe6af7b
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1onDrawFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x93bf0 */ ldr x9, [x2];
    /* 0x93bf4 */ mov x8, x5;
    /* 0x93bf8 */ mov x1, x4;
    /* 0x93bfc */ ldr w4, [sp, #8];
    /* 0x93c00 */ ldr w5, [sp, #0x10];
    /* 0x93c04 */ mov x3, x7;
    /* 0x93c08 */ ldr x6, [x9, #0x30];
    /* 0x93c0c */ mov x0, x2;
    /* 0x93c10 */ mov x2, x8;
    /* 0x93c14 */ br x6;
}
