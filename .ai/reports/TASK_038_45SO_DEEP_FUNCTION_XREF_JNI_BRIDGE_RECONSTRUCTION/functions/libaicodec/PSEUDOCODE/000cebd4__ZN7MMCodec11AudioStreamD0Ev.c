// Library: libaicodec.so
// Function ID: libaicodec::0xcebd4
// Recovered Name: _ZN7MMCodec11AudioStreamD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xcebd4 | Size: 36 bytes | SHA256: 42183f608805f931c5dca09b31f7fc6797c21a9249b6932ef3295f4ce720afe6
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN7MMCodec11AudioStreamD1Ev, _ZdlPv

void _ZN7MMCodec11AudioStreamD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0xcebd4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xcebd8 */ str x19, [sp, #0x10];
    /* 0xcebdc */ mov x29, sp;
    /* 0xcebe0 */ mov x19, x0;
    _ZN7MMCodec11AudioStreamD1Ev();
    /* 0xcebe8 */ mov x0, x19;
    /* 0xcebec */ ldr x19, [sp, #0x10];
    /* 0xcebf0 */ ldp x29, x30, [sp], #0x20;
    /* 0xcebf4 */ b #0x1f4650;
}
