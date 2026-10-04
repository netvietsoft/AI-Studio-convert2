// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99b70
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadPublicParamConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99b70 | Size: 148 bytes | SHA256: 7197e398eb8c68e02667fd864f5151212c490e5b1b5cd204a4e09b48c472282d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface28loadPublicParamConfigurationEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadPublicParamConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x99b70 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99b74 */ stp x22, x21, [sp, #0x10];
    /* 0x99b78 */ stp x20, x19, [sp, #0x20];
    /* 0x99b7c */ mov x29, sp;
    /* 0x99b80 */ mov x21, x2;
    /* 0x99b84 */ cbz x4, #0x99bdc;
    /* 0x99b88 */ ldr x8, [x0];
    /* 0x99b8c */ mov x1, x4;
    /* 0x99b90 */ mov x2, xzr;
    /* 0x99b94 */ mov x19, x4;
    /* 0x99b98 */ mov x20, x0;
    _ZN8mtlabar39Interface28loadPublicParamConfigurationEPKc();
    return x0;
}
