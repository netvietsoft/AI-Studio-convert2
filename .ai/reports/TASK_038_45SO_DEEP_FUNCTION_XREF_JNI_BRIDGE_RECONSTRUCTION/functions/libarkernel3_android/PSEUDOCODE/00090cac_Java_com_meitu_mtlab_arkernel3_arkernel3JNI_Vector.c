// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90cac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90cac | Size: 232 bytes | SHA256: 10649275a34decf3eafbb9bfdda86d6b8258002c8e10f057ae24e5cf79540319
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x90cac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x90cb0 */ str x21, [sp, #0x10];
    /* 0x90cb4 */ stp x20, x19, [sp, #0x20];
    /* 0x90cb8 */ mov x29, sp;
    /* 0x90cbc */ tbnz w4, #0x1f, #0x90ce8;
    /* 0x90cc0 */ ldp x8, x9, [x2];
    /* 0x90cc4 */ sub x9, x9, x8;
    /* 0x90cc8 */ lsr x9, x9, #3;
    /* 0x90ccc */ cmp w9, w4;
    /* 0x90cd0 */ b.le #0x90ce8;
    /* 0x90cd4 */ ldr x0, [x8, w4, uxtw #3];
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
