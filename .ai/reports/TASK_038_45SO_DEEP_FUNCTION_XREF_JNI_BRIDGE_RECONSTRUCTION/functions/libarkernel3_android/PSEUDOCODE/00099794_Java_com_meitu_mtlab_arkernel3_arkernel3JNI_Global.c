// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99794
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1registerBoldFontFamily
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99794 | Size: 224 bytes | SHA256: b09f88e0496e35b77e32a7a5cc1f579c6fcfb6959a3368c55e6899dfe34a62dc
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting22registerBoldFontFamilyEPKcS2_

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1registerBoldFontFamily(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x99794 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x99798 */ str x23, [sp, #0x10];
    /* 0x9979c */ stp x22, x21, [sp, #0x20];
    /* 0x997a0 */ stp x20, x19, [sp, #0x30];
    /* 0x997a4 */ mov x29, sp;
    /* 0x997a8 */ mov x19, x3;
    /* 0x997ac */ mov x21, x2;
    /* 0x997b0 */ mov x20, x0;
    /* 0x997b4 */ cbz x2, #0x99800;
    /* 0x997b8 */ ldr x8, [x20];
    /* 0x997bc */ mov x0, x20;
    _ZN8mtlabar313GlobalSetting22registerBoldFontFamilyEPKcS2_();
    return x0;
}
