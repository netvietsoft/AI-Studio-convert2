// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20b30
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctionsC2EiiNS_14PVGPixelFormatEiiS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20b30 | Size: 104 bytes | SHA256: 524bb33d61c28e5ee2169aeadf93d0ce49ee4feb4142f1f8e1086cd94e278b42
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGCOLOR17PVGColorFunctionsC2EiiNS_14PVGPixelFormatEiiS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x20b30 */ adrp x8, #0x5f000;
    /* 0x20b34 */ mov x9, x0;
    /* 0x20b38 */ ldr x8, [x8, #0x500];
    /* 0x20b3c */ stp wzr, w1, [x0, #8];
    /* 0x20b40 */ stp w2, w3, [x0, #0x10];
    /* 0x20b44 */ add x8, x8, #0x10;
    /* 0x20b48 */ stp w4, w5, [x0, #0x28];
    /* 0x20b4c */ str x8, [x0];
    /* 0x20b50 */ adrp x8, #0xd000;
    /* 0x20b54 */ ldr q0, [x8, #0xef0];
    /* 0x20b58 */ mov w8, #1;
    return x0;
}
