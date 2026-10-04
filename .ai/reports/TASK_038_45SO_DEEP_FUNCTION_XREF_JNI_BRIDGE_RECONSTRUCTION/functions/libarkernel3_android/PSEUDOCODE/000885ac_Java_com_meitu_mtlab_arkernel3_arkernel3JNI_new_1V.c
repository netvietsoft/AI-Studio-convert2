// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x885ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColor_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x885ac | Size: 72 bytes | SHA256: 5128f8858b22967495f3e5bd013fd23d76d6456baac19b7a37ed415b76dcc0ca
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColor_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x885ac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x885b0 */ stp x20, x19, [sp, #0x10];
    /* 0x885b4 */ mov x29, sp;
    /* 0x885b8 */ mov w0, #0x18;
    /* 0x885bc */ mov x20, x2;
    _Znwm();
    /* 0x885c4 */ mov x19, x0;
    /* 0x885c8 */ mov x1, x20;
    sub_885f4();
    /* 0x885d0 */ mov x0, x19;
    /* 0x885d4 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
