// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9374c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextPathConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9374c | Size: 132 bytes | SHA256: 0f875485e44042b5707cbd7fc362440bfb08675d1cff5e0a96d9b23c2d9a2b36
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils19parseTextPathConfigEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextPathConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x9374c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x93750 */ stp x22, x21, [sp, #0x10];
    /* 0x93754 */ stp x20, x19, [sp, #0x20];
    /* 0x93758 */ mov x29, sp;
    /* 0x9375c */ cbz x2, #0x937a8;
    /* 0x93760 */ ldr x8, [x0];
    /* 0x93764 */ mov x19, x2;
    /* 0x93768 */ mov x1, x2;
    /* 0x9376c */ mov x2, xzr;
    /* 0x93770 */ mov x20, x0;
    /* 0x93774 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils19parseTextPathConfigEPKc();
    _ZN8mtlabar39TextUtils19parseTextPathConfigEPKc();
    return x0;
}
