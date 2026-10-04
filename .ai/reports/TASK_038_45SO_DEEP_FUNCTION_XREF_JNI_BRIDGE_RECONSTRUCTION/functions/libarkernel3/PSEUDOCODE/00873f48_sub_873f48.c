// Library: libarkernel3.so
// Function ID: libarkernel3::0x873f48
// Recovered Name: sub_873f48
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x873f48 | Size: 868 bytes | SHA256: 6cffa9c23a9d5d2b9ca5dca8b107509955e09c360cda028e6cefbf57309569ff
// Callers: 0 | Callees: 12 | Imports: 4

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_BLEND_MULTIPLY"
//   ";MEITU_BLEND_NORMAL"
//   ";MEITU_BLEND_SCREEN"
//   ";MEITU_MASK_CHANNEL(x) (1.0 - (x).r)"

void sub_873f48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 217 instructions
    /* 0x873f48 */ stp x29, x30, [sp, #0x30];
    /* 0x873f4c */ stp x22, x21, [sp, #0x40];
    /* 0x873f50 */ stp x20, x19, [sp, #0x50];
    /* 0x873f54 */ add x29, sp, #0x30;
    /* 0x873f58 */ mrs x22, tpidr_el0;
    /* 0x873f5c */ mov x19, x0;
    /* 0x873f60 */ ldr x8, [x22, #0x28];
    /* 0x873f64 */ stur x8, [x29, #-8];
    sub_aa2a10();
    sub_aa1934();
    /* 0x873f70 */ ldrb w8, [x0, #2];
    sub_a5fe88();
    sub_aa2a10();
    sub_aa1c78();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_a7fc58();
    sub_a7b2a8();
    _ZdlPv();
    sub_86e9a4();
    sub_aa2a10();
    sub_aa1c78();
    sub_a7fc58();
    sub_a7fc4c();
    sub_aa2af4();
    sub_86d664();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_aa2a10();
    sub_aa1c78();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_a7fc58();
    sub_a7b2a8();
    return x0;
    sub_aa2a10();
    sub_aa191c();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
