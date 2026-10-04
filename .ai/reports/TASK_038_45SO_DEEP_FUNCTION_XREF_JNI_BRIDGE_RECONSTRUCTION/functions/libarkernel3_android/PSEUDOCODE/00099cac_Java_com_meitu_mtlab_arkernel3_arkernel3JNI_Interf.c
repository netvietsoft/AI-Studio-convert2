// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99cac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99cac | Size: 148 bytes | SHA256: 7200dfd4a171ecedfbeaf175eba6f40e4e6d9a0a297ddf1cc5ada7a824ad5468
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface17loadConfigurationEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x99cac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99cb0 */ stp x22, x21, [sp, #0x10];
    /* 0x99cb4 */ stp x20, x19, [sp, #0x20];
    /* 0x99cb8 */ mov x29, sp;
    /* 0x99cbc */ mov x21, x2;
    /* 0x99cc0 */ cbz x4, #0x99d14;
    /* 0x99cc4 */ ldr x8, [x0];
    /* 0x99cc8 */ mov x1, x4;
    /* 0x99ccc */ mov x2, xzr;
    /* 0x99cd0 */ mov x19, x4;
    /* 0x99cd4 */ mov x20, x0;
    _ZN8mtlabar39Interface17loadConfigurationEPKc();
    _ZN8mtlabar39Interface17loadConfigurationEPKc();
    return x0;
}
