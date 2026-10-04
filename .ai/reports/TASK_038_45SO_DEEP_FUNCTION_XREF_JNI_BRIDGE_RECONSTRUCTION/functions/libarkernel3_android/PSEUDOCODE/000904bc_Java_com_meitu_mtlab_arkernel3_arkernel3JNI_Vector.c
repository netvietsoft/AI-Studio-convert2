// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x904bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x904bc | Size: 236 bytes | SHA256: c4970247f22cd39f95eb78fc1df422b29fefa9da8edd8080ad9ad636bb583df9
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x904bc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x904c0 */ str x21, [sp, #0x10];
    /* 0x904c4 */ stp x20, x19, [sp, #0x20];
    /* 0x904c8 */ mov x29, sp;
    /* 0x904cc */ tbnz w4, #0x1f, #0x904f8;
    /* 0x904d0 */ ldp x8, x9, [x2];
    /* 0x904d4 */ sub x9, x9, x8;
    /* 0x904d8 */ lsr x9, x9, #3;
    /* 0x904dc */ cmp w9, w4;
    /* 0x904e0 */ b.le #0x904f8;
    /* 0x904e4 */ str x5, [x8, w4, uxtw #3];
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
