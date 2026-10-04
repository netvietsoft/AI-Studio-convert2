// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91118
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91118 | Size: 232 bytes | SHA256: 1a48a87ed9eba3ac3911702c58acccf2e8754fb4625471db9688a0af58049c7b
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x91118 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9111c */ str x21, [sp, #0x10];
    /* 0x91120 */ stp x20, x19, [sp, #0x20];
    /* 0x91124 */ mov x29, sp;
    /* 0x91128 */ tbnz w4, #0x1f, #0x91154;
    /* 0x9112c */ ldp x8, x9, [x2];
    /* 0x91130 */ sub x9, x9, x8;
    /* 0x91134 */ lsr x9, x9, #3;
    /* 0x91138 */ cmp w9, w4;
    /* 0x9113c */ b.le #0x91154;
    /* 0x91140 */ ldr x0, [x8, w4, uxtw #3];
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
