// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20e80
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions12setHWContextERKNS_12PVGHWContextE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20e80 | Size: 208 bytes | SHA256: 1805a7193d1702fb141787bdf8c911ffecb28aa0d81de2a80a5b420b2f20ac9a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

void _ZN8PVGCOLOR17PVGColorFunctions12setHWContextERKNS_12PVGHWContextE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x20e80 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x20e84 */ stp x20, x19, [sp, #0x10];
    /* 0x20e88 */ mov x29, sp;
    /* 0x20e8c */ ldr x8, [x0, #0x48];
    /* 0x20e90 */ mov x19, x0;
    /* 0x20e94 */ mov x20, x1;
    /* 0x20e98 */ cbz x8, #0x20f24;
    /* 0x20e9c */ ldr w9, [x8, #0x10];
    /* 0x20ea0 */ ldr w10, [x20, #0x10];
    /* 0x20ea4 */ cmp w9, w10;
    /* 0x20ea8 */ b.ne #0x20efc;
    return x0;
    _Znwm();
    return x0;
}
