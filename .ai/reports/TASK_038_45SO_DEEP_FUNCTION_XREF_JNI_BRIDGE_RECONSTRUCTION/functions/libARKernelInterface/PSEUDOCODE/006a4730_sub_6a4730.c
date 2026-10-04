// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x6a4730
// Recovered Name: sub_6a4730
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6a4730 | Size: 536 bytes | SHA256: 2b15446fe9ae1535099e2fa0c927e83af3161f50c7f1f2b060ec00f9bdeedbda
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%d"
//   "(a,b)    "
//   ";definedBlend"
//   "BlendColorBurn(a,b)"
//   "BlendColorDodge(a,b)"

void sub_6a4730(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 134 instructions
    /* 0x6a4730 */ stp x29, x30, [sp, #0xc0];
    /* 0x6a4734 */ str x23, [sp, #0xd0];
    /* 0x6a4738 */ stp x22, x21, [sp, #0xe0];
    /* 0x6a473c */ stp x20, x19, [sp, #0xf0];
    /* 0x6a4740 */ add x29, sp, #0xc0;
    /* 0x6a4744 */ mrs x23, tpidr_el0;
    /* 0x6a4748 */ mov w21, w1;
    /* 0x6a474c */ mov x19, x8;
    /* 0x6a4750 */ ldr x8, [x23, #0x28];
    /* 0x6a4754 */ mov w20, w2;
    /* 0x6a4758 */ mov x22, x0;
    sub_6a4948();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    return x0;
    __stack_chk_fail();
}
