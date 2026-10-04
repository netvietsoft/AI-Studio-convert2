// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88948
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88948 | Size: 272 bytes | SHA256: 1be898e70bed3899ec5ad7c460b56221a034683ff3854a217d648c66d70e5281
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "std::vector< mtlabar3::Color >::value_type const & reference is null"
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x88948 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8894c */ str x21, [sp, #0x10];
    /* 0x88950 */ stp x20, x19, [sp, #0x20];
    /* 0x88954 */ mov x29, sp;
    /* 0x88958 */ cbz x5, #0x8898c;
    /* 0x8895c */ tbnz w4, #0x1f, #0x889a8;
    /* 0x88960 */ ldp x8, x9, [x2];
    /* 0x88964 */ sub x9, x9, x8;
    /* 0x88968 */ lsr x9, x9, #4;
    /* 0x8896c */ cmp w9, w4;
    /* 0x88970 */ b.le #0x889a8;
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
