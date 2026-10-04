// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88d18
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88d18 | Size: 232 bytes | SHA256: 202f2863b96a31c37454dbac9f7704bbd2a7b8295c4848c1447c25acd29d669f
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x88d18 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88d1c */ str x21, [sp, #0x10];
    /* 0x88d20 */ stp x20, x19, [sp, #0x20];
    /* 0x88d24 */ mov x29, sp;
    /* 0x88d28 */ tbnz w4, #0x1f, #0x88d54;
    /* 0x88d2c */ ldp x8, x9, [x2];
    /* 0x88d30 */ sub x9, x9, x8;
    /* 0x88d34 */ lsr x9, x9, #3;
    /* 0x88d38 */ cmp w9, w4;
    /* 0x88d3c */ b.le #0x88d54;
    /* 0x88d40 */ add x0, x8, w4, uxtw #3;
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
