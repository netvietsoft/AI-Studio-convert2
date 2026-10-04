// Library: libffavc.so
// Function ID: libffavc::0x5614c
// Recovered Name: sub_5614c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5614c | Size: 136 bytes | SHA256: a8dc418affca01cfe3e1111a3d78ac8fd402824f1af7d1dc004c6eea7b18140a
// Callers: 0 | Callees: 1 | Imports: 0


void sub_5614c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x5614c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56150 */ str x19, [sp, #0x10];
    /* 0x56154 */ mov x29, sp;
    /* 0x56158 */ adrp x8, #0x105000;
    /* 0x5615c */ add x8, x8, #0xd18;
    /* 0x56160 */ mov x19, x0;
    /* 0x56164 */ str x8, [x0];
    sub_560f0();
    /* 0x5616c */ mov x0, x19;
    /* 0x56170 */ ldr x19, [sp, #0x10];
    /* 0x56174 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
