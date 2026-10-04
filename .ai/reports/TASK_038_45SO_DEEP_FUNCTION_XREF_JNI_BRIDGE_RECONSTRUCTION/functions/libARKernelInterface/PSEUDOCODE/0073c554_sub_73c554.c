// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x73c554
// Recovered Name: sub_73c554
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x73c554 | Size: 5388 bytes | SHA256: 374f3731f670246f7b583ac6115b85822948056837e81fd4e389469934368477
// Callers: 0 | Callees: 16 | Imports: 5

// Calls external APIs: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_, _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "%.4lf,%.4lf"
//   "%.lf,%.lf,%.lf,%.lf,%.lf"
//   "+#"
//   "AnimationOnBackground"
//   "AnimationOnForeground"

void sub_73c554(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1347 instructions
    /* 0x73c554 */ stp x29, x30, [sp, #0x10];
    /* 0x73c558 */ stp x28, x27, [sp, #0x20];
    /* 0x73c55c */ stp x26, x25, [sp, #0x30];
    /* 0x73c560 */ stp x24, x23, [sp, #0x40];
    /* 0x73c564 */ stp x22, x21, [sp, #0x50];
    /* 0x73c568 */ stp x20, x19, [sp, #0x60];
    /* 0x73c56c */ add x29, sp, #0x10;
    /* 0x73c570 */ sub sp, sp, #0x2c0;
    /* 0x73c574 */ mrs x25, tpidr_el0;
    /* 0x73c578 */ adrp x22, #0x1ad000;
    /* 0x73c57c */ add x22, x22, #0x439;
    sub_58f19c();
    sub_58f19c();
    sub_68bc60();
    _ZdlPv();
    _ZdlPv();
    sub_5ab12c();
    sub_5ab8b8();
    sub_5a8a28();
    sub_5ab6d0();
    sub_570f58();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    sub_58f19c();
    _ZdlPv();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZdlPv();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZdlPv();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZdlPv();
    sub_5ace44();
    sub_5ad808();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    sub_5ace44();
    sub_5ae2e0();
    sub_5acfa0();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68efb8();
    _ZdlPv();
    sub_73da60();
    sub_58f19c();
    _ZdlPv();
    sub_73da60();
    sub_58f19c();
    _ZdlPv();
    sub_73da60();
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68efb8();
    _ZdlPv();
    sub_570f58();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5ab604();
    sub_5acfa0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5ab178();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
