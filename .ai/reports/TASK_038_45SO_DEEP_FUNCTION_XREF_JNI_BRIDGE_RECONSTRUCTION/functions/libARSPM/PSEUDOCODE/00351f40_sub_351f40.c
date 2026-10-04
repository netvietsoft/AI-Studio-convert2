// Library: libARSPM.so
// Function ID: libARSPM::0x351f40
// Recovered Name: sub_351f40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x351f40 | Size: 568 bytes | SHA256: 81c947acd33097a9c60fab013148b338d0f65a1c13928444e0c7233e0d980c29
// Callers: 0 | Callees: 12 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "AAHairline"
//   "AAHairlinePathRenderer::onDrawPath"

void sub_351f40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 142 instructions
    /* 0x351f40 */ stp x29, x30, [sp, #0x88];
    /* 0x351f44 */ str x25, [sp, #0x98];
    /* 0x351f48 */ stp x24, x23, [sp, #0xa0];
    /* 0x351f4c */ stp x22, x21, [sp, #0xb0];
    /* 0x351f50 */ stp x20, x19, [sp, #0xc0];
    /* 0x351f54 */ add x29, sp, #0x88;
    /* 0x351f58 */ ldr x8, [x1];
    /* 0x351f5c */ mov x19, x1;
    /* 0x351f60 */ ldr x20, [x8, #0x20];
    /* 0x351f64 */ ldrb w8, [x20, #0x54];
    /* 0x351f68 */ cbz w8, #0x351f90;
    sub_1d8fb8();
    sub_26462c();
    sub_1d93f8();
    sub_18d2e0();
    sub_1da744();
    sub_33974c();
    sub_313864();
    sub_18d364();
    _Znwm();
    _Znwm();
    sub_3518a0();
    sub_352178();
    sub_18d3dc();
    sub_3200b4();
    sub_18d3dc();
    return x0;
    return x0;
}
