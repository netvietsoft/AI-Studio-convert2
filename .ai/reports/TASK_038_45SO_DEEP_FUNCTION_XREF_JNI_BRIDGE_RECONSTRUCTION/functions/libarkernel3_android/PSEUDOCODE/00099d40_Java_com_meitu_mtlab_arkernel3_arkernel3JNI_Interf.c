// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99d40
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadConfigurationSync
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99d40 | Size: 148 bytes | SHA256: 5f36010b746576ba58f242f95dc602c5126f4f148d8fab388a229ddea1216c0e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface21loadConfigurationSyncEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadConfigurationSync(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x99d40 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99d44 */ stp x22, x21, [sp, #0x10];
    /* 0x99d48 */ stp x20, x19, [sp, #0x20];
    /* 0x99d4c */ mov x29, sp;
    /* 0x99d50 */ mov x21, x2;
    /* 0x99d54 */ cbz x4, #0x99da8;
    /* 0x99d58 */ ldr x8, [x0];
    /* 0x99d5c */ mov x1, x4;
    /* 0x99d60 */ mov x2, xzr;
    /* 0x99d64 */ mov x19, x4;
    /* 0x99d68 */ mov x20, x0;
    _ZN8mtlabar39Interface21loadConfigurationSyncEPKc();
    _ZN8mtlabar39Interface21loadConfigurationSyncEPKc();
    return x0;
}
