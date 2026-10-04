// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e2d0
// Recovered Name: sub_2e2d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e2d0 | Size: 240 bytes | SHA256: 79898a052097c46137ec87e8490c018020e2e8936fe7f5490a2dc00ddacd04c7
// Callers: 3 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN3MFX3RefD2Ev, _ZdlPv

void sub_2e2d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 60 instructions
    /* 0x2e2d0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e2d4 */ str x19, [sp, #0x10];
    /* 0x2e2d8 */ mov x29, sp;
    /* 0x2e2dc */ adrp x8, #0x81000;
    /* 0x2e2e0 */ mov x19, x0;
    /* 0x2e2e4 */ ldr x8, [x8, #0xcc0];
    /* 0x2e2e8 */ ldr x0, [x0, #0x178];
    /* 0x2e2ec */ add x8, x8, #0x10;
    /* 0x2e2f0 */ str x8, [x19];
    /* 0x2e2f4 */ cbz x0, #0x2e300;
    /* 0x2e2f8 */ str x0, [x19, #0x180];
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
    _ZdlPv();
}
