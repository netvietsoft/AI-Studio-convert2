// Library: libPVGLive.so
// Function ID: libPVGLive::0x275d4
// Recovered Name: sub_275d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x275d4 | Size: 36 bytes | SHA256: f2ba38573128321ed2174eed0e156d62127cac8c5bdc1418f757992674a50574
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_275d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x275d4 */ ldrb w8, [x0, #8];
    /* 0x275d8 */ adrp x9, #0x94000;
    /* 0x275dc */ add x9, x9, #0xd98;
    /* 0x275e0 */ str x9, [x0];
    /* 0x275e4 */ tbnz w8, #0, #0x275ec;
    return x0;
    /* 0x275ec */ ldr x0, [x0, #0x18];
    /* 0x275f0 */ b #0x904e0;
    /* 0x275f4 */ brk #1;
}
