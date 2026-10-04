// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ef18
// Recovered Name: _ZN2ge9AttrValue10NamedAttrs17MutableAttrMapDefEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ef18 | Size: 24 bytes | SHA256: ca3feb3eca8625961f6d74d93c0f9a3579bb45c205e42825de08f253ff533d9b
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN2ge9AttrValue10NamedAttrs17MutableAttrMapDefEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3ef18 */ ldr x0, [x0, #8];
    /* 0x3ef1c */ cbz x0, #0x3ef2c;
    /* 0x3ef20 */ ldr x8, [x0];
    /* 0x3ef24 */ ldr x1, [x8, #0x40];
    /* 0x3ef28 */ br x1;
    return x0;
}
