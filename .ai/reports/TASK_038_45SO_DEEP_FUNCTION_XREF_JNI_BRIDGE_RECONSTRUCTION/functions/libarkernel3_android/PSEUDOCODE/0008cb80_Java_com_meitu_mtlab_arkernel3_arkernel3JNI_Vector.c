// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8cb80
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8cb80 | Size: 300 bytes | SHA256: 66e3aadbbd094b0ba06946b01321f1753ffa328a0f3c215422aabf1eccdee004
// Callers: 0 | Callees: 3 | Imports: 7

// Calls external APIs: _ZNSt11logic_errorC2EPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "std::vector< mtlabar3::SelectHighlightConfig >::value_type const & reference is null"
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectHighlightConfig_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 75 instructions
    /* 0x8cb80 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8cb84 */ stp x22, x21, [sp, #0x10];
    /* 0x8cb88 */ stp x20, x19, [sp, #0x20];
    /* 0x8cb8c */ mov x29, sp;
    /* 0x8cb90 */ mov x19, x0;
    /* 0x8cb94 */ cbz x5, #0x8cbe0;
    /* 0x8cb98 */ tbnz w4, #0x1f, #0x8cc00;
    /* 0x8cb9c */ ldp x8, x9, [x2];
    /* 0x8cba0 */ sub x9, x9, x8;
    /* 0x8cba4 */ lsr x9, x9, #5;
    /* 0x8cba8 */ cmp w9, w4;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
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
