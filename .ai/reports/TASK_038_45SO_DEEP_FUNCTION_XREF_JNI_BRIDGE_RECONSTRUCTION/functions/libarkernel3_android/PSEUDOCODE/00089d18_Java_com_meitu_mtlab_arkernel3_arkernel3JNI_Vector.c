// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89d18
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorFloat_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89d18 | Size: 232 bytes | SHA256: 0397ebfe02b59532b97a6b8101da4f1e365f2d0c3abcf3e8437345eeb091731b
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorFloat_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x89d18 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x89d1c */ str x21, [sp, #0x10];
    /* 0x89d20 */ stp x20, x19, [sp, #0x20];
    /* 0x89d24 */ mov x29, sp;
    /* 0x89d28 */ tbnz w4, #0x1f, #0x89d54;
    /* 0x89d2c */ ldp x8, x9, [x2];
    /* 0x89d30 */ sub x9, x9, x8;
    /* 0x89d34 */ lsr x9, x9, #2;
    /* 0x89d38 */ cmp w9, w4;
    /* 0x89d3c */ b.le #0x89d54;
    /* 0x89d40 */ ldr s0, [x8, w4, uxtw #2];
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
