// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fc9b4
// Recovered Name: _ZN12MTImageKitNS11DyeHairInfoD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3fc9b4 | Size: 188 bytes | SHA256: 07c8be765e99bd0ee2e1b99095c072bdeea904757f72db1bb4f440ff818183a5
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN12MTImageKitNS11DyeHairInfoD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x3fc9b4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3fc9b8 */ str x21, [sp, #0x10];
    /* 0x3fc9bc */ stp x20, x19, [sp, #0x20];
    /* 0x3fc9c0 */ mov x29, sp;
    /* 0x3fc9c4 */ ldr x20, [x0];
    /* 0x3fc9c8 */ cbz x20, #0x3fca60;
    /* 0x3fc9cc */ ldr x21, [x0, #8];
    /* 0x3fc9d0 */ mov x19, x0;
    /* 0x3fc9d4 */ mov x0, x20;
    /* 0x3fc9d8 */ cmp x21, x20;
    /* 0x3fc9dc */ b.ne #0x3fca00;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
