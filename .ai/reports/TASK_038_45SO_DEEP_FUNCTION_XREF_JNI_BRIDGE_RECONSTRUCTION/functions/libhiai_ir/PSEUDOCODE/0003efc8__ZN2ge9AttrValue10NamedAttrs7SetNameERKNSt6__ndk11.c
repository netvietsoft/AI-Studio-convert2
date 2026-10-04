// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3efc8
// Recovered Name: _ZN2ge9AttrValue10NamedAttrs7SetNameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3efc8 | Size: 24 bytes | SHA256: f8947bf923e410c3c9f5cfb09040a39df23fc152c18fced515d0bbcc0bdcbf72
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN2ge9AttrValue10NamedAttrs7SetNameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3efc8 */ ldr x0, [x0, #8];
    /* 0x3efcc */ cbz x0, #0x3efdc;
    /* 0x3efd0 */ ldr x8, [x0];
    /* 0x3efd4 */ ldr x2, [x8, #0x30];
    /* 0x3efd8 */ br x2;
    return x0;
}
