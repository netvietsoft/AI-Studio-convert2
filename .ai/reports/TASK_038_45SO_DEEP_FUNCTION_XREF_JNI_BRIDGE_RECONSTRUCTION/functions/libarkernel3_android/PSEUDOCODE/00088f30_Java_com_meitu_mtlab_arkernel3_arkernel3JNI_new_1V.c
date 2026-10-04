// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88f30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorString_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88f30 | Size: 72 bytes | SHA256: 445aed3197ce1b21844292ddc8fc76d11c479f55e9707028ca1852f3885334a3
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorString_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x88f30 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x88f34 */ stp x20, x19, [sp, #0x10];
    /* 0x88f38 */ mov x29, sp;
    /* 0x88f3c */ mov w0, #0x18;
    /* 0x88f40 */ mov x20, x2;
    _Znwm();
    /* 0x88f48 */ mov x19, x0;
    /* 0x88f4c */ mov x1, x20;
    sub_88f78();
    /* 0x88f54 */ mov x0, x19;
    /* 0x88f58 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
