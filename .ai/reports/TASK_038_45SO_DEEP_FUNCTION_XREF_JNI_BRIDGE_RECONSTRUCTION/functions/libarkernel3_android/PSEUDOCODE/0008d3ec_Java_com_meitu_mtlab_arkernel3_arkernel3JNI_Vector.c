// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d3ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d3ec | Size: 232 bytes | SHA256: d90f7142c4bd9fafddcc099c0e06284d0560f1e8cc311a69a5b7cda33128060f
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x8d3ec */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8d3f0 */ str x21, [sp, #0x10];
    /* 0x8d3f4 */ stp x20, x19, [sp, #0x20];
    /* 0x8d3f8 */ mov x29, sp;
    /* 0x8d3fc */ tbnz w4, #0x1f, #0x8d428;
    /* 0x8d400 */ ldp x8, x9, [x2];
    /* 0x8d404 */ sub x9, x9, x8;
    /* 0x8d408 */ lsr x9, x9, #2;
    /* 0x8d40c */ cmp w9, w4;
    /* 0x8d410 */ b.le #0x8d428;
    /* 0x8d414 */ ldr w0, [x8, w4, uxtw #2];
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
