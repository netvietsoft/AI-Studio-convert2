// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ee78
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsC2EPN4hiai13INamedAttrDefEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ee78 | Size: 40 bytes | SHA256: 6d001c92e3a5c8befc002e89b021a15bffe1da4f8bd6ac695ec39ff99f08b471
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN2ge9AttrValue10NamedAttrsC2EPN4hiai13INamedAttrDefEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x3ee78 */ adrp x8, #0xda000;
    /* 0x3ee7c */ ldr x8, [x8, #0x3d0];
    /* 0x3ee80 */ strb w2, [x0, #0x10];
    /* 0x3ee84 */ str xzr, [x0, #0x28];
    /* 0x3ee88 */ add x8, x8, #0x10;
    /* 0x3ee8c */ stp x8, x1, [x0];
    /* 0x3ee90 */ mov x8, x0;
    /* 0x3ee94 */ str xzr, [x8, #0x20]!;
    /* 0x3ee98 */ str x8, [x0, #0x18];
    return x0;
}
