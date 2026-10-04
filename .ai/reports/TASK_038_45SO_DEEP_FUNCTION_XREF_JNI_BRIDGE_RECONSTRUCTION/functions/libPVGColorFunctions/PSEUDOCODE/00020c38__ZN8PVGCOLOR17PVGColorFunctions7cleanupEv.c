// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20c38
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions7cleanupEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20c38 | Size: 68 bytes | SHA256: b5d480a25209aa1e5b63d779a4db3319c32007a1651f52d7580338eff67562cf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN8PVGCOLOR17PVGColorFunctions7cleanupEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x20c38 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x20c3c */ str x19, [sp, #0x10];
    /* 0x20c40 */ mov x29, sp;
    /* 0x20c44 */ mov x19, x0;
    /* 0x20c48 */ ldr x0, [x0, #0x48];
    /* 0x20c4c */ cbz x0, #0x20c58;
    _ZdlPv();
    /* 0x20c54 */ str xzr, [x19, #0x48];
    /* 0x20c58 */ ldr x0, [x19, #0x50];
    /* 0x20c5c */ cbz x0, #0x20c70;
    /* 0x20c60 */ ldr x8, [x0];
    return x0;
}
