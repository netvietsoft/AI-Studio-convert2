// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90d94
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90d94 | Size: 236 bytes | SHA256: efcbb126a9167609d0fd32c43e6ae167df834e9657a5a866dfaab45b22be29c2
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x90d94 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x90d98 */ str x21, [sp, #0x10];
    /* 0x90d9c */ stp x20, x19, [sp, #0x20];
    /* 0x90da0 */ mov x29, sp;
    /* 0x90da4 */ tbnz w4, #0x1f, #0x90dd0;
    /* 0x90da8 */ ldp x8, x9, [x2];
    /* 0x90dac */ sub x9, x9, x8;
    /* 0x90db0 */ lsr x9, x9, #3;
    /* 0x90db4 */ cmp w9, w4;
    /* 0x90db8 */ b.le #0x90dd0;
    /* 0x90dbc */ str x5, [x8, w4, uxtw #3];
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
