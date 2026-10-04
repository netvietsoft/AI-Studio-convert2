// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x939e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseAnimationConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x939e0 | Size: 132 bytes | SHA256: 50508399281ca4ce42fe3ee7dcc17927810bd8cf3d9cc4d0987689338807f2bd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils20parseAnimationConfigEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseAnimationConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x939e0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x939e4 */ stp x22, x21, [sp, #0x10];
    /* 0x939e8 */ stp x20, x19, [sp, #0x20];
    /* 0x939ec */ mov x29, sp;
    /* 0x939f0 */ cbz x2, #0x93a3c;
    /* 0x939f4 */ ldr x8, [x0];
    /* 0x939f8 */ mov x19, x2;
    /* 0x939fc */ mov x1, x2;
    /* 0x93a00 */ mov x2, xzr;
    /* 0x93a04 */ mov x20, x0;
    /* 0x93a08 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils20parseAnimationConfigEPKc();
    _ZN8mtlabar39TextUtils20parseAnimationConfigEPKc();
    return x0;
}
