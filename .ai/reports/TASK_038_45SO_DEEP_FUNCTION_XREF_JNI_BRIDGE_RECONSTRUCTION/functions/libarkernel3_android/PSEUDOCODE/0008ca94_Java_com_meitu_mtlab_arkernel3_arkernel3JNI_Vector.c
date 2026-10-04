// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ca94
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ca94 | Size: 236 bytes | SHA256: 3132b55c66231277cfadd01189c753d4ba2aa6e26ab185f2282eb0406dfb1f88
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x8ca94 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8ca98 */ str x21, [sp, #0x10];
    /* 0x8ca9c */ stp x20, x19, [sp, #0x20];
    /* 0x8caa0 */ mov x29, sp;
    /* 0x8caa4 */ tbnz w4, #0x1f, #0x8cad4;
    /* 0x8caa8 */ ldp x8, x9, [x2];
    /* 0x8caac */ sub x9, x9, x8;
    /* 0x8cab0 */ lsr x9, x9, #5;
    /* 0x8cab4 */ cmp w9, w4;
    /* 0x8cab8 */ b.le #0x8cad4;
    /* 0x8cabc */ mov w9, w4;
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
