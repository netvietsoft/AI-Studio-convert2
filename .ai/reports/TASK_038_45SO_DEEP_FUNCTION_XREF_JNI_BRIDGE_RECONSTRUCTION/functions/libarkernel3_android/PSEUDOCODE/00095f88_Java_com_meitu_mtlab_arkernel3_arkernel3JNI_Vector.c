// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95f88
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95f88 | Size: 232 bytes | SHA256: 8068d6a2033d963dc4466fcb4a0b8327f94aa854443bf2bf133eade6dfd959f9
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x95f88 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x95f8c */ str x21, [sp, #0x10];
    /* 0x95f90 */ stp x20, x19, [sp, #0x20];
    /* 0x95f94 */ mov x29, sp;
    /* 0x95f98 */ tbnz w4, #0x1f, #0x95fc4;
    /* 0x95f9c */ ldp x8, x9, [x2];
    /* 0x95fa0 */ sub x9, x9, x8;
    /* 0x95fa4 */ lsr x9, x9, #3;
    /* 0x95fa8 */ cmp w9, w4;
    /* 0x95fac */ b.le #0x95fc4;
    /* 0x95fb0 */ ldr x0, [x8, w4, uxtw #3];
    return x0;
    __cxa_allocate_exception();
    _ZNSt11logic_errorC2EPKc();
    __cxa_throw();
    __cxa_free_exception();
    __cxa_begin_catch();
    sub_882c8();
    __cxa_end_catch();
    __cxa_end_catch();
    sub_9c5c8();
    sub_8844c();
}
