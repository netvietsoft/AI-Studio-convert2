// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99dd4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1parsingConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99dd4 | Size: 148 bytes | SHA256: 6af5a30f19cdccacd7ae035582857b7fc3c4521f8b87c50857bec0fad5f18fd8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface20parsingConfigurationEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1parsingConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x99dd4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99dd8 */ stp x22, x21, [sp, #0x10];
    /* 0x99ddc */ stp x20, x19, [sp, #0x20];
    /* 0x99de0 */ mov x29, sp;
    /* 0x99de4 */ mov x21, x2;
    /* 0x99de8 */ cbz x4, #0x99e3c;
    /* 0x99dec */ ldr x8, [x0];
    /* 0x99df0 */ mov x1, x4;
    /* 0x99df4 */ mov x2, xzr;
    /* 0x99df8 */ mov x19, x4;
    /* 0x99dfc */ mov x20, x0;
    _ZN8mtlabar39Interface20parsingConfigurationEPKc();
    _ZN8mtlabar39Interface20parsingConfigurationEPKc();
    return x0;
}
