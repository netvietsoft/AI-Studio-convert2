// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x649d8
// Recovered Name: _ZN8PVGVIDEO10PVGContextD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x649d8 | Size: 432 bytes | SHA256: b96f8160c25a50c4d9c5fb75de9d16bd853af3468d9210ee837211e59de767ec
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: _ZN8PVGVIDEO6PVGRef7releaseEv, _ZN8PVGVIDEO6PVGRefD2Ev, _ZdlPv

void _ZN8PVGVIDEO10PVGContextD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 108 instructions
    /* 0x649d8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x649dc */ str x21, [sp, #0x10];
    /* 0x649e0 */ stp x20, x19, [sp, #0x20];
    /* 0x649e4 */ mov x29, sp;
    /* 0x649e8 */ adrp x8, #0x11a000;
    /* 0x649ec */ mov x19, x0;
    /* 0x649f0 */ ldr x8, [x8, #0xd50];
    /* 0x649f4 */ ldr x0, [x0, #0x68];
    /* 0x649f8 */ add x8, x8, #0x10;
    /* 0x649fc */ str x8, [x19];
    /* 0x64a00 */ cbz x0, #0x64a0c;
    _ZN8PVGVIDEO6PVGRef7releaseEv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_64b88();
}
