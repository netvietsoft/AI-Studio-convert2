// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9395c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextWarpConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9395c | Size: 132 bytes | SHA256: 1962e45115a5b5fd86108d1e2c95c0592187b9bd8957df2046b76ccfd24820c7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils19parseTextWarpConfigEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextWarpConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x9395c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x93960 */ stp x22, x21, [sp, #0x10];
    /* 0x93964 */ stp x20, x19, [sp, #0x20];
    /* 0x93968 */ mov x29, sp;
    /* 0x9396c */ cbz x2, #0x939b8;
    /* 0x93970 */ ldr x8, [x0];
    /* 0x93974 */ mov x19, x2;
    /* 0x93978 */ mov x1, x2;
    /* 0x9397c */ mov x2, xzr;
    /* 0x93980 */ mov x20, x0;
    /* 0x93984 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils19parseTextWarpConfigEPKc();
    _ZN8mtlabar39TextUtils19parseTextWarpConfigEPKc();
    return x0;
}
