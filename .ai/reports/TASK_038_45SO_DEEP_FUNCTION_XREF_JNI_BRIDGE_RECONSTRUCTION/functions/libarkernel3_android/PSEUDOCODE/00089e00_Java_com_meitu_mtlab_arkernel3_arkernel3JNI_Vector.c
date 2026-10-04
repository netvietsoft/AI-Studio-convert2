// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89e00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorFloat_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89e00 | Size: 236 bytes | SHA256: 889825b4cce778c8368890bc1621bc9915248428f5f73974dfa066ca01afe87f
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorFloat_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x89e00 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x89e04 */ str x21, [sp, #0x10];
    /* 0x89e08 */ stp x20, x19, [sp, #0x20];
    /* 0x89e0c */ mov x29, sp;
    /* 0x89e10 */ tbnz w4, #0x1f, #0x89e3c;
    /* 0x89e14 */ ldp x8, x9, [x2];
    /* 0x89e18 */ sub x9, x9, x8;
    /* 0x89e1c */ lsr x9, x9, #2;
    /* 0x89e20 */ cmp w9, w4;
    /* 0x89e24 */ b.le #0x89e3c;
    /* 0x89e28 */ str s0, [x8, w4, uxtw #2];
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
