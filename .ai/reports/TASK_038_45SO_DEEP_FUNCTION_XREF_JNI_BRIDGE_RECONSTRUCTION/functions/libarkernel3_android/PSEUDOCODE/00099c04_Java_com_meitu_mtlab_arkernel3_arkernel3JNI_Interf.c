// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99c04
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadPublicParamConfigurationSync
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99c04 | Size: 148 bytes | SHA256: fa7acb35e53b38be442e5356e422e61de23efa853df7b0877255712af7ec2cb3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface32loadPublicParamConfigurationSyncEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1loadPublicParamConfigurationSync(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x99c04 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99c08 */ stp x22, x21, [sp, #0x10];
    /* 0x99c0c */ stp x20, x19, [sp, #0x20];
    /* 0x99c10 */ mov x29, sp;
    /* 0x99c14 */ mov x21, x2;
    /* 0x99c18 */ cbz x4, #0x99c70;
    /* 0x99c1c */ ldr x8, [x0];
    /* 0x99c20 */ mov x1, x4;
    /* 0x99c24 */ mov x2, xzr;
    /* 0x99c28 */ mov x19, x4;
    /* 0x99c2c */ mov x20, x0;
    _ZN8mtlabar39Interface32loadPublicParamConfigurationSyncEPKc();
    return x0;
}
