// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3eee8
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3eee8 | Size: 24 bytes | SHA256: 3fe3dd09c7f39d6751a9f67a1c0690d6d5aa2a82c9610333ca60c613cc7548ca
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN2ge9AttrValue10NamedAttrsD1Ev, _ZdlPv

void _ZN2ge9AttrValue10NamedAttrsD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x3eee8 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x3eeec */ mov x19, x0;
    _ZN2ge9AttrValue10NamedAttrsD1Ev();
    /* 0x3eef4 */ mov x0, x19;
    /* 0x3eef8 */ ldp x30, x19, [sp], #0x10;
    /* 0x3eefc */ b #0xced70;
}
