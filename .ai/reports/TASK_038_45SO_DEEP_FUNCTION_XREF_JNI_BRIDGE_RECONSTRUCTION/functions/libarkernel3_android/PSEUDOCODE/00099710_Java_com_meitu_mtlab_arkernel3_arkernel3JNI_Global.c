// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99710
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1unregisterFont
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99710 | Size: 132 bytes | SHA256: 4a0d471bec029f11e7572c03bb48087e4c687bc471b55aca54e2917b25de413f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting14unregisterFontEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1unregisterFont(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x99710 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99714 */ str x21, [sp, #0x10];
    /* 0x99718 */ stp x20, x19, [sp, #0x20];
    /* 0x9971c */ mov x29, sp;
    /* 0x99720 */ cbz x2, #0x99770;
    /* 0x99724 */ ldr x8, [x0];
    /* 0x99728 */ mov x19, x2;
    /* 0x9972c */ mov x1, x2;
    /* 0x99730 */ mov x2, xzr;
    /* 0x99734 */ mov x20, x0;
    /* 0x99738 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar313GlobalSetting14unregisterFontEPKc();
    return x0;
}
