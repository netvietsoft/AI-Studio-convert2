// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d4d4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d4d4 | Size: 236 bytes | SHA256: 574dac9eb940b1976b3f3cedc3e92e5b59912f9e0381c3dd171ca22204978841
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x8d4d4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8d4d8 */ str x21, [sp, #0x10];
    /* 0x8d4dc */ stp x20, x19, [sp, #0x20];
    /* 0x8d4e0 */ mov x29, sp;
    /* 0x8d4e4 */ tbnz w4, #0x1f, #0x8d510;
    /* 0x8d4e8 */ ldp x8, x9, [x2];
    /* 0x8d4ec */ sub x9, x9, x8;
    /* 0x8d4f0 */ lsr x9, x9, #2;
    /* 0x8d4f4 */ cmp w9, w4;
    /* 0x8d4f8 */ b.le #0x8d510;
    /* 0x8d4fc */ str w5, [x8, w4, uxtw #2];
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
