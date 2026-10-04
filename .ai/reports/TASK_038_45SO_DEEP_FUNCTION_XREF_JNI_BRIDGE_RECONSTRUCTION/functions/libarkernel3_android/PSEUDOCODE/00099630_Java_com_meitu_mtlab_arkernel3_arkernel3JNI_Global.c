// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99630
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1registerFont
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99630 | Size: 224 bytes | SHA256: 214d1fcd2de64e6bf8aca7b00f846e875842a257e69f4a3b8f24713db4c44fad
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting12registerFontEPKcS2_

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1registerFont(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x99630 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x99634 */ str x23, [sp, #0x10];
    /* 0x99638 */ stp x22, x21, [sp, #0x20];
    /* 0x9963c */ stp x20, x19, [sp, #0x30];
    /* 0x99640 */ mov x29, sp;
    /* 0x99644 */ mov x19, x3;
    /* 0x99648 */ mov x21, x2;
    /* 0x9964c */ mov x20, x0;
    /* 0x99650 */ cbz x2, #0x9969c;
    /* 0x99654 */ ldr x8, [x20];
    /* 0x99658 */ mov x0, x20;
    _ZN8mtlabar313GlobalSetting12registerFontEPKcS2_();
    return x0;
}
