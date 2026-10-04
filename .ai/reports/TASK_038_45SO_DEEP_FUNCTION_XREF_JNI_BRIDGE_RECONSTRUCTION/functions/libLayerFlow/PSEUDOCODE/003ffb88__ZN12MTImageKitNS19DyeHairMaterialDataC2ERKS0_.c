// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3ffb88
// Recovered Name: _ZN12MTImageKitNS19DyeHairMaterialDataC2ERKS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ffb88 | Size: 268 bytes | SHA256: 1c714a67f915eed1903a57529519c4ccef2a3adf3f50533973bc27dcfffa8d9e
// Callers: 2 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN12MTImageKitNS19DyeHairMaterialDataC2ERKS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x3ffb88 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3ffb8c */ stp x20, x19, [sp, #0x10];
    /* 0x3ffb90 */ mov x29, sp;
    /* 0x3ffb94 */ ldrb w8, [x1];
    /* 0x3ffb98 */ mov x20, x1;
    /* 0x3ffb9c */ mov x19, x0;
    /* 0x3ffba0 */ tbnz w8, #0, #0x3ffbec;
    /* 0x3ffba4 */ ldr x8, [x20, #0x10];
    /* 0x3ffba8 */ ldr q0, [x20];
    /* 0x3ffbac */ str x8, [x19, #0x10];
    /* 0x3ffbb0 */ str q0, [x19];
    sub_2bc260();
    sub_2bc260();
    sub_2bc260();
    return x0;
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}
