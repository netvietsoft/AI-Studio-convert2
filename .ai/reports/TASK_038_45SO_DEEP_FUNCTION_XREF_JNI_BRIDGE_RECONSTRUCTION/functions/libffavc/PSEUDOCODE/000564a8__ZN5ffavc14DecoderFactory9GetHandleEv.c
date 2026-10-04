// Library: libffavc.so
// Function ID: libffavc::0x564a8
// Recovered Name: _ZN5ffavc14DecoderFactory9GetHandleEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x564a8 | Size: 88 bytes | SHA256: 53a84f9dfe34f66ef56d88c6f83e238394d788a21318cb9fa2270d7384d56ad6
// Callers: 0 | Callees: 2 | Imports: 0


void _ZN5ffavc14DecoderFactory9GetHandleEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x564a8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x564ac */ mov x29, sp;
    /* 0x564b0 */ nop ;
    /* 0x564b4 */ adr x8, #0x122e58;
    /* 0x564b8 */ ldarb w8, [x8];
    /* 0x564bc */ tbz w8, #0, #0x564d0;
    /* 0x564c0 */ nop ;
    /* 0x564c4 */ adr x0, #0x122e50;
    /* 0x564c8 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x564d0 */ nop ;
    sub_e223c();
    sub_e2380();
}
