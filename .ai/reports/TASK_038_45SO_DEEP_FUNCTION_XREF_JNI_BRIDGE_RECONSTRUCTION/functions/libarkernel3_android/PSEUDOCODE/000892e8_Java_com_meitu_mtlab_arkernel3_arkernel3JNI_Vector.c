// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x892e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x892e8 | Size: 288 bytes | SHA256: 5799c569f497013248bbfc63d772188b5dd17bd6256c5f2f2990c187a828e073
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 72 instructions
    /* 0x892e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x892ec */ str x21, [sp, #0x10];
    /* 0x892f0 */ stp x20, x19, [sp, #0x20];
    /* 0x892f4 */ mov x29, sp;
    /* 0x892f8 */ tbnz w4, #0x1f, #0x89350;
    /* 0x892fc */ ldp x8, x9, [x2];
    /* 0x89300 */ mov w10, #0xaaab;
    /* 0x89304 */ movk w10, #0xaaaa, lsl #16;
    /* 0x89308 */ sub x9, x9, x8;
    /* 0x8930c */ lsr x9, x9, #3;
    /* 0x89310 */ mul w9, w9, w10;
    __cxa_allocate_exception();
    _ZNSt11logic_errorC2EPKc();
    __cxa_throw();
    __cxa_free_exception();
    __cxa_begin_catch();
    sub_882c8();
    __cxa_end_catch();
    return x0;
    __cxa_end_catch();
    sub_9c5c8();
    sub_8844c();
}
