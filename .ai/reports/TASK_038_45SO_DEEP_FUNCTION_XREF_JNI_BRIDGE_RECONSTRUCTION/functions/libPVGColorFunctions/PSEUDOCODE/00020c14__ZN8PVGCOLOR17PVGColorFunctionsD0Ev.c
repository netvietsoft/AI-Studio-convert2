// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20c14
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctionsD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20c14 | Size: 36 bytes | SHA256: d0827ca2b54a8c17be214af6e8653d1313b917acf129eb8c43d82223ee4b355f
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8PVGCOLOR17PVGColorFunctionsD1Ev, _ZdlPv

void _ZN8PVGCOLOR17PVGColorFunctionsD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x20c14 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x20c18 */ str x19, [sp, #0x10];
    /* 0x20c1c */ mov x29, sp;
    /* 0x20c20 */ mov x19, x0;
    _ZN8PVGCOLOR17PVGColorFunctionsD1Ev();
    /* 0x20c28 */ mov x0, x19;
    /* 0x20c2c */ ldr x19, [sp, #0x10];
    /* 0x20c30 */ ldp x29, x30, [sp], #0x20;
    /* 0x20c34 */ b #0x58c20;
}
