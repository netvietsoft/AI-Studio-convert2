// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88860
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88860 | Size: 232 bytes | SHA256: 08a484d17d99b412799b6515ba86087963b05265c53175e2c31914c83dc5a96b
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x88860 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88864 */ str x21, [sp, #0x10];
    /* 0x88868 */ stp x20, x19, [sp, #0x20];
    /* 0x8886c */ mov x29, sp;
    /* 0x88870 */ tbnz w4, #0x1f, #0x8889c;
    /* 0x88874 */ ldp x8, x9, [x2];
    /* 0x88878 */ sub x9, x9, x8;
    /* 0x8887c */ lsr x9, x9, #4;
    /* 0x88880 */ cmp w9, w4;
    /* 0x88884 */ b.le #0x8889c;
    /* 0x88888 */ add x0, x8, w4, uxtw #4;
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
