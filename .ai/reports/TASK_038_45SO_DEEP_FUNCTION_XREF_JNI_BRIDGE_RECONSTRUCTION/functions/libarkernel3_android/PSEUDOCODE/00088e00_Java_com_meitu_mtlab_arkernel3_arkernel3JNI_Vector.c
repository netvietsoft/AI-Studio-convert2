// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88e00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88e00 | Size: 272 bytes | SHA256: eae36b68e652087fc0c577c723532144246f0b66740e87153236b5a65c5b0939
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "std::vector< mtlabar3::Float2 >::value_type const & reference is null"
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x88e00 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88e04 */ str x21, [sp, #0x10];
    /* 0x88e08 */ stp x20, x19, [sp, #0x20];
    /* 0x88e0c */ mov x29, sp;
    /* 0x88e10 */ cbz x5, #0x88e44;
    /* 0x88e14 */ tbnz w4, #0x1f, #0x88e60;
    /* 0x88e18 */ ldp x8, x9, [x2];
    /* 0x88e1c */ sub x9, x9, x8;
    /* 0x88e20 */ lsr x9, x9, #3;
    /* 0x88e24 */ cmp w9, w4;
    /* 0x88e28 */ b.le #0x88e60;
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
