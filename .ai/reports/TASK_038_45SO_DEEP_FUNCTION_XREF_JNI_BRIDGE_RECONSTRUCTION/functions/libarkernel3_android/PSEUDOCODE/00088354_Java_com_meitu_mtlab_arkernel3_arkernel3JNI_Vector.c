// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88354
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88354 | Size: 248 bytes | SHA256: 12d638a6ca59c7a8fdcd93a79e5e1dd21682c6333df25da3e8710bf713aba767
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x88354 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88358 */ str x21, [sp, #0x10];
    /* 0x8835c */ stp x20, x19, [sp, #0x20];
    /* 0x88360 */ mov x29, sp;
    /* 0x88364 */ tbnz w4, #0x1f, #0x883a0;
    /* 0x88368 */ ldp x8, x9, [x2];
    /* 0x8836c */ mov w10, #0xcccd;
    /* 0x88370 */ movk w10, #0xcccc, lsl #16;
    /* 0x88374 */ sub x9, x9, x8;
    /* 0x88378 */ lsr x9, x9, #2;
    /* 0x8837c */ mul w9, w9, w10;
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
