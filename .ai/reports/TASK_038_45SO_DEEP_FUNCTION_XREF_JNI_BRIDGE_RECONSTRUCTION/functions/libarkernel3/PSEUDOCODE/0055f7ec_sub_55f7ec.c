// Library: libarkernel3.so
// Function ID: libarkernel3::0x55f7ec
// Recovered Name: sub_55f7ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55f7ec | Size: 1580 bytes | SHA256: ad2f2dcfde35d941d14db861a7b9d37389077b972b9590687ce916a36c24c537
// Callers: 0 | Callees: 8 | Imports: 6

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk19to_stringEi, _ZdlPv, memcpy, memmove

void sub_55f7ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 395 instructions
    /* 0x55f7ec */ stp x29, x30, [sp, #0x110];
    /* 0x55f7f0 */ stp x28, x27, [sp, #0x120];
    /* 0x55f7f4 */ stp x26, x25, [sp, #0x130];
    /* 0x55f7f8 */ stp x24, x23, [sp, #0x140];
    /* 0x55f7fc */ stp x22, x21, [sp, #0x150];
    /* 0x55f800 */ stp x20, x19, [sp, #0x160];
    /* 0x55f804 */ add x29, sp, #0x110;
    /* 0x55f808 */ mov x26, x8;
    /* 0x55f80c */ mrs x8, tpidr_el0;
    /* 0x55f810 */ mov x20, x1;
    /* 0x55f814 */ str x8, [sp, #0x18];
    sub_560034();
    sub_565168();
    sub_a69d38();
    sub_a69d38();
    sub_a6a3b4();
    sub_562578();
    sub_562578();
    sub_5600a4();
    sub_562ac8();
    _ZdlPv();
    sub_560420();
    memmove();
    sub_562578();
    sub_560034();
    sub_560420();
    memmove();
    _ZNSt6__ndk19to_stringEi();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_562578();
    memcpy();
    _ZdlPv();
    memcpy();
    _ZdlPv();
    _ZdlPv();
}
