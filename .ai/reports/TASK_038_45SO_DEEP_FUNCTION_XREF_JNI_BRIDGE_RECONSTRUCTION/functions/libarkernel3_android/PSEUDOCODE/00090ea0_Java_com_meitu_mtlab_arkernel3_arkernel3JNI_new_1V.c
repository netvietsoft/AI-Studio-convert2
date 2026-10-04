// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90ea0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorLineLayoutConfigInterface_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90ea0 | Size: 72 bytes | SHA256: 3c3c905cdc04d6c44403548f31297daa6d7e74b5357bc22ab9aadcfcb5761fb5
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorLineLayoutConfigInterface_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x90ea0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90ea4 */ stp x20, x19, [sp, #0x10];
    /* 0x90ea8 */ mov x29, sp;
    /* 0x90eac */ mov w0, #0x18;
    /* 0x90eb0 */ mov x20, x2;
    _Znwm();
    /* 0x90eb8 */ mov x19, x0;
    /* 0x90ebc */ mov x1, x20;
    sub_90ee8();
    /* 0x90ec4 */ mov x0, x19;
    /* 0x90ec8 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
