// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3ff8c0
// Recovered Name: _ZN12MTImageKitNS19DyeHairMaterialDataD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ff8c0 | Size: 100 bytes | SHA256: cef5b27579d2ffd840718468d9f668da5729ff0fa011a40c1d7a33a143e93ef2
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN12MTImageKitNS19DyeHairMaterialDataD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x3ff8c0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3ff8c4 */ str x19, [sp, #0x10];
    /* 0x3ff8c8 */ mov x29, sp;
    /* 0x3ff8cc */ ldrb w8, [x0, #0x30];
    /* 0x3ff8d0 */ mov x19, x0;
    /* 0x3ff8d4 */ tbnz w8, #0, #0x3ff8f4;
    /* 0x3ff8d8 */ ldrb w8, [x19, #0x18];
    /* 0x3ff8dc */ tbnz w8, #0, #0x3ff904;
    /* 0x3ff8e0 */ ldrb w8, [x19];
    /* 0x3ff8e4 */ tbnz w8, #0, #0x3ff914;
    /* 0x3ff8e8 */ ldr x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    _ZdlPv();
}
