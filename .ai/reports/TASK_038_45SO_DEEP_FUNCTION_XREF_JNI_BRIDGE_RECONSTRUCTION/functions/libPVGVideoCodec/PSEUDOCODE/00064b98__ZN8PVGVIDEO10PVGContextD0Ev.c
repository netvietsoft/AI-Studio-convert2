// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x64b98
// Recovered Name: _ZN8PVGVIDEO10PVGContextD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x64b98 | Size: 36 bytes | SHA256: 414a2ec72f3ebacc77a4d815f39750eca048756e522ebba8446b51b5b90e600c
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8PVGVIDEO10PVGContextD1Ev, _ZdlPv

void _ZN8PVGVIDEO10PVGContextD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x64b98 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x64b9c */ str x19, [sp, #0x10];
    /* 0x64ba0 */ mov x29, sp;
    /* 0x64ba4 */ mov x19, x0;
    _ZN8PVGVIDEO10PVGContextD1Ev();
    /* 0x64bac */ mov x0, x19;
    /* 0x64bb0 */ ldr x19, [sp, #0x10];
    /* 0x64bb4 */ ldp x29, x30, [sp], #0x20;
    /* 0x64bb8 */ b #0x1111b0;
}
