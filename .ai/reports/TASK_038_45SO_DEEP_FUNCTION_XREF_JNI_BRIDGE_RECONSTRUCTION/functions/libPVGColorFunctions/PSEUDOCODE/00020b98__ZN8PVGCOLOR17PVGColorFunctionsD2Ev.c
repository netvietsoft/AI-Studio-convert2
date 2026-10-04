// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20b98
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctionsD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20b98 | Size: 124 bytes | SHA256: 84ecc1ce5de63f7d90a2d465bece26a1248cbc2d4b40e5256366615a964e33d7
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdaPv, _ZdlPv

void _ZN8PVGCOLOR17PVGColorFunctionsD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x20b98 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x20b9c */ str x19, [sp, #0x10];
    /* 0x20ba0 */ mov x29, sp;
    /* 0x20ba4 */ adrp x8, #0x5f000;
    /* 0x20ba8 */ mov x19, x0;
    /* 0x20bac */ ldr x8, [x8, #0x500];
    /* 0x20bb0 */ ldr x0, [x0, #0x48];
    /* 0x20bb4 */ add x8, x8, #0x10;
    /* 0x20bb8 */ str x8, [x19];
    /* 0x20bbc */ cbz x0, #0x20bc8;
    _ZdlPv();
    _ZdaPv();
    _ZdaPv();
}
