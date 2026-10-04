// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96070
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96070 | Size: 236 bytes | SHA256: efddd43e0e15f25efae2dd58b088e5f39b98b0dfb3ac52c2a737a3dbf11475b5
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x96070 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x96074 */ str x21, [sp, #0x10];
    /* 0x96078 */ stp x20, x19, [sp, #0x20];
    /* 0x9607c */ mov x29, sp;
    /* 0x96080 */ tbnz w4, #0x1f, #0x960ac;
    /* 0x96084 */ ldp x8, x9, [x2];
    /* 0x96088 */ sub x9, x9, x8;
    /* 0x9608c */ lsr x9, x9, #3;
    /* 0x96090 */ cmp w9, w4;
    /* 0x96094 */ b.le #0x960ac;
    /* 0x96098 */ str x5, [x8, w4, uxtw #3];
    return x0;
    __cxa_allocate_exception();
    _ZNSt11logic_errorC2EPKc();
    __cxa_throw();
    __cxa_free_exception();
    __cxa_begin_catch();
    sub_882c8();
    __cxa_end_catch();
    sub_9c5c8();
    sub_8844c();
}
