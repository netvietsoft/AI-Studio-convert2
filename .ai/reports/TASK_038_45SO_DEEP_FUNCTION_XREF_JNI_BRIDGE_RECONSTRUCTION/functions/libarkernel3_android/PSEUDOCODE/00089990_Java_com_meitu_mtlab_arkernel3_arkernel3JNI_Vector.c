// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89990
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89990 | Size: 236 bytes | SHA256: 6d2ebce962ee2983e02a992651211cfd14361eccbb25ef9982c01a04028b2c5e
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x89990 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x89994 */ str x21, [sp, #0x10];
    /* 0x89998 */ stp x20, x19, [sp, #0x20];
    /* 0x8999c */ mov x29, sp;
    /* 0x899a0 */ tbnz w4, #0x1f, #0x899cc;
    /* 0x899a4 */ ldp x8, x9, [x2];
    /* 0x899a8 */ sub x9, x9, x8;
    /* 0x899ac */ lsr x9, x9, #2;
    /* 0x899b0 */ cmp w9, w4;
    /* 0x899b4 */ b.le #0x899cc;
    /* 0x899b8 */ str w5, [x8, w4, uxtw #2];
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
