// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa35cd0
// Recovered Name: sub_a35cd0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa35cd0 | Size: 5156 bytes | SHA256: b9c9b58050df0bcda65b34b18af45a1967fbcb2c2f7bfc0aa8b6312b6fec0607
// Callers: 0 | Callees: 11 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "AnimalFontColor"
//   "AnimalInfo"
//   "BlendShapeInfo"
//   "DeviceFontColor"
//   "DeviceInfo"

void sub_a35cd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1289 instructions
    /* 0xa35cd0 */ stp x29, x30, [sp, #0x50];
    /* 0xa35cd4 */ str x25, [sp, #0x60];
    /* 0xa35cd8 */ stp x24, x23, [sp, #0x70];
    /* 0xa35cdc */ stp x22, x21, [sp, #0x80];
    /* 0xa35ce0 */ stp x20, x19, [sp, #0x90];
    /* 0xa35ce4 */ add x29, sp, #0x50;
    /* 0xa35ce8 */ mrs x24, tpidr_el0;
    /* 0xa35cec */ mov x21, x1;
    /* 0xa35cf0 */ mov x20, x0;
    /* 0xa35cf4 */ ldr x8, [x24, #0x28];
    /* 0xa35cf8 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5a8de8();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_5a8d3c();
    sub_a37170();
    sub_5cb47c();
    sub_a37170();
    sub_5cb47c();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_a37170();
    sub_5cb47c();
    sub_a37170();
    sub_5cb47c();
    sub_a37170();
    sub_5cb47c();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_a37170();
    sub_5cb47c();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_a37170();
    sub_5cb47c();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8d0c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a8cfc();
    sub_a370f4();
    sub_5a8cfc();
    sub_5a8cfc();
    sub_a370f4();
    sub_5a8cfc();
    sub_a37170();
    sub_5cb47c();
    sub_5a8cfc();
    sub_a370f4();
    sub_5cb9b8();
    sub_951740();
    sub_5a8cfc();
    sub_5a8cfc();
    sub_5a8cfc();
    sub_94e020();
    sub_5a8de8();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
