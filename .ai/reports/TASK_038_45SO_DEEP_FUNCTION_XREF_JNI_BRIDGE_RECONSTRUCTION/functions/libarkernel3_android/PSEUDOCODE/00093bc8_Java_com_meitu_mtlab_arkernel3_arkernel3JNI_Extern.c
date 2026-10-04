// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93bc8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1activeConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93bc8 | Size: 40 bytes | SHA256: 1c7cf0c44b35360cd39b6c4a1ba1f671dbedf03bb7ea9b42cbe7a142b82c18da
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ExternalFunctionCallback_1activeConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x93bc8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93bcc */ mov x29, sp;
    /* 0x93bd0 */ ldr x8, [x2];
    /* 0x93bd4 */ mov x0, x2;
    /* 0x93bd8 */ mov x1, x4;
    /* 0x93bdc */ ldr x8, [x8, #0x28];
    /* 0x93be0 */ blr x8;
    /* 0x93be4 */ and w0, w0, #1;
    /* 0x93be8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
