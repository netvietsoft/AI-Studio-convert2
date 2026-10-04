// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ef98
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsaSERKS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ef98 | Size: 48 bytes | SHA256: ea600a9482878011547d56c5ee638ccb24ae08358e6f6e0594a473cf9386a1b8
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN2ge9AttrValue10NamedAttrsaSERKS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x3ef98 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x3ef9c */ mov x19, x0;
    /* 0x3efa0 */ cmp x1, x0;
    /* 0x3efa4 */ b.eq #0x3efbc;
    /* 0x3efa8 */ ldr x0, [x19, #8];
    /* 0x3efac */ ldr x1, [x1, #8];
    /* 0x3efb0 */ ldr x8, [x0];
    /* 0x3efb4 */ ldr x8, [x8, #0x10];
    /* 0x3efb8 */ blr x8;
    /* 0x3efbc */ mov x0, x19;
    /* 0x3efc0 */ ldp x30, x19, [sp], #0x10;
    return x0;
}
