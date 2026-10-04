// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d024
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectAnimationConfig_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d024 | Size: 300 bytes | SHA256: 701c3062f5a5be298324c95e24f95db629e4b32f474212dc84e3377ebf607b64
// Callers: 0 | Callees: 3 | Imports: 7

// Calls external APIs: _ZNSt11logic_errorC2EPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, __cxa_allocate_exception, __cxa_begin_catch, __cxa_end_catch, __cxa_free_exception, __cxa_throw
// Strings referenced:
//   "std::vector< mtlabar3::SelectAnimationConfig >::value_type const & reference is null"
//   "vector index out of range"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectAnimationConfig_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 75 instructions
    /* 0x8d024 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8d028 */ stp x22, x21, [sp, #0x10];
    /* 0x8d02c */ stp x20, x19, [sp, #0x20];
    /* 0x8d030 */ mov x29, sp;
    /* 0x8d034 */ mov x19, x0;
    /* 0x8d038 */ cbz x5, #0x8d084;
    /* 0x8d03c */ tbnz w4, #0x1f, #0x8d0a4;
    /* 0x8d040 */ ldp x8, x9, [x2];
    /* 0x8d044 */ sub x9, x9, x8;
    /* 0x8d048 */ lsr x9, x9, #5;
    /* 0x8d04c */ cmp w9, w4;
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
