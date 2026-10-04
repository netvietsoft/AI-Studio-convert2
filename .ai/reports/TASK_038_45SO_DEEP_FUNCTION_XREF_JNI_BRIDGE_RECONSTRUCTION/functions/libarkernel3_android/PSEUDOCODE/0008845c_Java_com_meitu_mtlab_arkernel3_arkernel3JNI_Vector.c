// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8845c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8845c | Size: 304 bytes | SHA256: b9d9a9c6ee17ada176aed94f0e9e69c60af60a858175ecfff81c6598a9d3968c
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZNSt11logic_errorC2EPKc, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "std::vector< mtlabar3::ColorA >::value_type const & reference is null"
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 76 instructions
    /* 0x8845c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88460 */ str x21, [sp, #0x10];
    /* 0x88464 */ stp x20, x19, [sp, #0x20];
    /* 0x88468 */ mov x29, sp;
    /* 0x8846c */ cbz x5, #0x884c0;
    /* 0x88470 */ tbnz w4, #0x1f, #0x884dc;
    /* 0x88474 */ ldp x8, x9, [x2];
    /* 0x88478 */ mov w10, #0xcccd;
    /* 0x8847c */ movk w10, #0xcccc, lsl #16;
    /* 0x88480 */ sub x9, x9, x8;
    /* 0x88484 */ lsr x9, x9, #2;
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
