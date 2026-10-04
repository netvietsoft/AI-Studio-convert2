// Library: libarkernel3.so
// Function ID: libarkernel3::0xa96adc
// Recovered Name: sub_a96adc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa96adc | Size: 856 bytes | SHA256: e84007a14f2f05b907c2302a3007e416a9f51ea9ff6fc10e3d4df35b460ba65c
// Callers: 0 | Callees: 4 | Imports: 2

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, __stack_chk_fail
// Strings referenced:
//   "Multiply"
//   "Normal"
//   "Screen"
//   "Softlight"

void sub_a96adc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 214 instructions
    /* 0xa96adc */ stp x29, x30, [sp, #0x40];
    /* 0xa96ae0 */ stp x28, x27, [sp, #0x50];
    /* 0xa96ae4 */ stp x26, x25, [sp, #0x60];
    /* 0xa96ae8 */ stp x24, x23, [sp, #0x70];
    /* 0xa96aec */ stp x22, x21, [sp, #0x80];
    /* 0xa96af0 */ stp x20, x19, [sp, #0x90];
    /* 0xa96af4 */ add x29, sp, #0x40;
    /* 0xa96af8 */ movi v0.2d, #0000000000000000;
    /* 0xa96afc */ mrs x25, tpidr_el0;
    /* 0xa96b00 */ adrp x24, #0x293000;
    /* 0xa96b04 */ add x24, x24, #0x2ac;
    sub_a96ff8();
    sub_a96ff8();
    sub_a96ff8();
    sub_a96ff8();
    sub_a96ff8();
    sub_a96ff8();
    sub_a9811c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_a9811c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_a9811c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_a9811c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_a980cc();
    return x0;
    sub_a980cc();
    sub_106b814();
    __stack_chk_fail();
}
