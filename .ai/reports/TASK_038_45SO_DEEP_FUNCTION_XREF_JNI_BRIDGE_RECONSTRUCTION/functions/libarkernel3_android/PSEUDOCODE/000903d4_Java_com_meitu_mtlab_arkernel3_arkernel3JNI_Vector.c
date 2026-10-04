// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x903d4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x903d4 | Size: 232 bytes | SHA256: e33b89400d70e6ee6444be95792e825bb5a8c4925d5050b6518d51f43fe6014f
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x903d4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x903d8 */ str x21, [sp, #0x10];
    /* 0x903dc */ stp x20, x19, [sp, #0x20];
    /* 0x903e0 */ mov x29, sp;
    /* 0x903e4 */ tbnz w4, #0x1f, #0x90410;
    /* 0x903e8 */ ldp x8, x9, [x2];
    /* 0x903ec */ sub x9, x9, x8;
    /* 0x903f0 */ lsr x9, x9, #3;
    /* 0x903f4 */ cmp w9, w4;
    /* 0x903f8 */ b.le #0x90410;
    /* 0x903fc */ ldr x0, [x8, w4, uxtw #3];
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
