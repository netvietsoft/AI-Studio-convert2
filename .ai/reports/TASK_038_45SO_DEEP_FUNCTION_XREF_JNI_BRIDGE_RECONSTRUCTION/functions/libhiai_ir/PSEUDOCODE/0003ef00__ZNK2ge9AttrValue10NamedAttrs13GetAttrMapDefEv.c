// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ef00
// Recovered Name: _ZNK2ge9AttrValue10NamedAttrs13GetAttrMapDefEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ef00 | Size: 24 bytes | SHA256: ecc7275b4063f42462cbbef9388d3d2338e7b53e798ee166fe804f0aae88baf3
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK2ge9AttrValue10NamedAttrs13GetAttrMapDefEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3ef00 */ ldr x0, [x0, #8];
    /* 0x3ef04 */ cbz x0, #0x3ef14;
    /* 0x3ef08 */ ldr x8, [x0];
    /* 0x3ef0c */ ldr x1, [x8, #0x38];
    /* 0x3ef10 */ br x1;
    return x0;
}
