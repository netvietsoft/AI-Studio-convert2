// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a494
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1pad_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a494 | Size: 136 bytes | SHA256: ba41abb1ef105ad55a4825bce89a8fd5742cef2fe040e10e40d40ad3df6e60cf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: strncpy

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1_1pad_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x8a494 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8a498 */ stp x22, x21, [sp, #0x10];
    /* 0x8a49c */ stp x20, x19, [sp, #0x20];
    /* 0x8a4a0 */ mov x29, sp;
    /* 0x8a4a4 */ mov x20, x2;
    /* 0x8a4a8 */ cbz x4, #0x8a508;
    /* 0x8a4ac */ ldr x8, [x0];
    /* 0x8a4b0 */ mov x1, x4;
    /* 0x8a4b4 */ mov x2, xzr;
    /* 0x8a4b8 */ mov x19, x4;
    /* 0x8a4bc */ mov x21, x0;
    strncpy();
    return x0;
}
