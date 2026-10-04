// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91200
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91200 | Size: 236 bytes | SHA256: d566f3c24e11a9aa63f9656cfbe85472581ef5b3327a02d70aacd401322f6d87
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x91200 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x91204 */ str x21, [sp, #0x10];
    /* 0x91208 */ stp x20, x19, [sp, #0x20];
    /* 0x9120c */ mov x29, sp;
    /* 0x91210 */ tbnz w4, #0x1f, #0x9123c;
    /* 0x91214 */ ldp x8, x9, [x2];
    /* 0x91218 */ sub x9, x9, x8;
    /* 0x9121c */ lsr x9, x9, #3;
    /* 0x91220 */ cmp w9, w4;
    /* 0x91224 */ b.le #0x9123c;
    /* 0x91228 */ str x5, [x8, w4, uxtw #3];
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
