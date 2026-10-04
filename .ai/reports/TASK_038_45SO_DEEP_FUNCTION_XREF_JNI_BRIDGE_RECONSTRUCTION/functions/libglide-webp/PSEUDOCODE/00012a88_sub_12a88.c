// Library: libglide-webp.so
// Function ID: libglide-webp::0x12a88
// Recovered Name: sub_12a88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x12a88 | Size: 68 bytes | SHA256: 3db5b23d69c995b759e8ecbab811b52d981cdfff5daf3c4d3e0882505f8e8dcf
// Callers: 0 | Callees: 0 | Imports: 0


void sub_12a88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x12a88 */ stp x29, x30, [sp, #0x10];
    /* 0x12a8c */ add x29, sp, #0x10;
    /* 0x12a90 */ ldr x8, [x0];
    /* 0x12a94 */ mov x19, x0;
    /* 0x12a98 */ ldr x8, [x8, #0x30];
    /* 0x12a9c */ blr x8;
    /* 0x12aa0 */ cbz x0, #0x12ac0;
    /* 0x12aa4 */ ldr x8, [x19];
    /* 0x12aa8 */ ldp x29, x30, [sp, #0x10];
    /* 0x12aac */ mov x1, x0;
    /* 0x12ab0 */ mov x0, x19;
    return x0;
}
