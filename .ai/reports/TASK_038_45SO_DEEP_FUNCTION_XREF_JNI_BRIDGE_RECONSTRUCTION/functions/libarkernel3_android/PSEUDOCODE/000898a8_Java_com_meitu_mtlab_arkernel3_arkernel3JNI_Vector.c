// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x898a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x898a8 | Size: 232 bytes | SHA256: 619f14eabd9e976cc81e2b3f1033ed01a40906b7979fbcf8542eba5773c01382
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x898a8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x898ac */ str x21, [sp, #0x10];
    /* 0x898b0 */ stp x20, x19, [sp, #0x20];
    /* 0x898b4 */ mov x29, sp;
    /* 0x898b8 */ tbnz w4, #0x1f, #0x898e4;
    /* 0x898bc */ ldp x8, x9, [x2];
    /* 0x898c0 */ sub x9, x9, x8;
    /* 0x898c4 */ lsr x9, x9, #2;
    /* 0x898c8 */ cmp w9, w4;
    /* 0x898cc */ b.le #0x898e4;
    /* 0x898d0 */ ldr w0, [x8, w4, uxtw #2];
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
