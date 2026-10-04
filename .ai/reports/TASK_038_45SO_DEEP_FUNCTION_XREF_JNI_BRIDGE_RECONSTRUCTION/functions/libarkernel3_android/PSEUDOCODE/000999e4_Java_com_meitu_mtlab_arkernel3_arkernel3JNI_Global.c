// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x999e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getSDKReleaseVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x999e4 | Size: 64 bytes | SHA256: aa5ebb2c8e1b92e6ef983b523caff841c6d7a118d1601a7a48c6ee97208cc923
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting20getSDKReleaseVersionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getSDKReleaseVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x999e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x999e8 */ str x19, [sp, #0x10];
    /* 0x999ec */ mov x29, sp;
    /* 0x999f0 */ mov x19, x0;
    _ZN8mtlabar313GlobalSetting20getSDKReleaseVersionEv();
    /* 0x999f8 */ cbz x0, #0x99a18;
    /* 0x999fc */ ldr x8, [x19];
    /* 0x99a00 */ mov x1, x0;
    /* 0x99a04 */ ldr x2, [x8, #0x538];
    /* 0x99a08 */ mov x0, x19;
    /* 0x99a0c */ ldr x19, [sp, #0x10];
    return x0;
}
