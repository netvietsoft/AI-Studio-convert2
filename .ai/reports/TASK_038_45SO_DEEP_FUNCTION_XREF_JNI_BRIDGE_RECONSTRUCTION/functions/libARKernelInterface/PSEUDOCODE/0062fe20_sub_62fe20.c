// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x62fe20
// Recovered Name: sub_62fe20
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x62fe20 | Size: 3260 bytes | SHA256: 8525bbb1143f0a5380dff570ebb67487edbed9668e3fc97a576dd5310e16fa94
// Callers: 4 | Callees: 18 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZdlPv, _Znwm, __stack_chk_fail, memmove
// Strings referenced:
//   "%.f,%.f,%.f,%.f"
//   "%.f,%.f,%.f,%.f,%.f"
//   "%d,%d"
//   "AddPath"
//   "AdditionalTexture"

void sub_62fe20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 815 instructions
    /* 0x62fe20 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x62fe24 */ stp x28, x27, [sp, #0x10];
    /* 0x62fe28 */ stp x26, x25, [sp, #0x20];
    /* 0x62fe2c */ stp x24, x23, [sp, #0x30];
    /* 0x62fe30 */ stp x22, x21, [sp, #0x40];
    /* 0x62fe34 */ stp x20, x19, [sp, #0x50];
    /* 0x62fe38 */ mov x29, sp;
    /* 0x62fe3c */ sub sp, sp, #0x1c0;
    /* 0x62fe40 */ mrs x23, tpidr_el0;
    /* 0x62fe44 */ mov x19, x0;
    /* 0x62fe48 */ mov x20, x1;
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    sub_630adc();
    sub_5ace44();
    sub_5ad578();
    sub_5ad7d8();
    sub_58f19c();
    sub_5acfa0();
    sub_5abbf8();
    memmove();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    sub_5abbf8();
    memmove();
    sub_5ad6b8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    sub_68fec4();
    _ZdlPv();
    sub_5acfa0();
    sub_a1925c();
    sub_a19288();
    sub_630c04();
    sub_58f19c();
    _ZdlPv();
    sub_630c04();
    sub_58f19c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    sub_630c04();
    sub_58f19c();
    _ZdlPv();
    sub_62b78c();
    sub_61d798();
    _ZdlPv();
    return x0;
    sub_59c568();
    __stack_chk_fail();
}
