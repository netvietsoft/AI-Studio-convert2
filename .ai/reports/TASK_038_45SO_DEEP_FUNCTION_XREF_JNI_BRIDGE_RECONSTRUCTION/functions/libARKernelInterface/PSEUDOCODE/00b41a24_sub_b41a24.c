// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb41a24
// Recovered Name: sub_b41a24
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb41a24 | Size: 4616 bytes | SHA256: 36f42d37f7bba50235a7efd8a5ed520667029f2a77bc7fe471d16c42d8d82b38
// Callers: 0 | Callees: 11 | Imports: 4

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, memmove
// Strings referenced:
//   "Alpha"
//   "AnimalMirrorH"
//   "AnimalMirrorV"
//   "AnimalOffset"
//   "AnimalRotate"

void sub_b41a24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1154 instructions
    /* 0xb41a24 */ stp x29, x30, [sp, #0x40];
    /* 0xb41a28 */ stp x24, x23, [sp, #0x50];
    /* 0xb41a2c */ stp x22, x21, [sp, #0x60];
    /* 0xb41a30 */ stp x20, x19, [sp, #0x70];
    /* 0xb41a34 */ add x29, sp, #0x40;
    /* 0xb41a38 */ mrs x24, tpidr_el0;
    /* 0xb41a3c */ mov x20, x1;
    /* 0xb41a40 */ mov x19, x0;
    /* 0xb41a44 */ ldr x8, [x24, #0x28];
    /* 0xb41a48 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5abbf8();
    memmove();
    sub_68c86c();
    sub_5a8f24();
    sub_68c87c();
    sub_bac034();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8da0();
    sub_5a8d0c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8da0();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
}
