// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c2758
// Recovered Name: sub_5c2758
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c2758 | Size: 1776 bytes | SHA256: 21ada265c68de074b1ebb102617cf3eba30de3cb1022692862755832ef06b371
// Callers: 0 | Callees: 19 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "ColorCollection"
//   "Enable"
//   "GlowConfig"
//   "GlowInAlpha"

void sub_5c2758(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 444 instructions
    /* 0x5c2758 */ stp x29, x30, [sp, #0x70];
    /* 0x5c275c */ stp x28, x27, [sp, #0x80];
    /* 0x5c2760 */ stp x26, x25, [sp, #0x90];
    /* 0x5c2764 */ stp x24, x23, [sp, #0xa0];
    /* 0x5c2768 */ stp x22, x21, [sp, #0xb0];
    /* 0x5c276c */ stp x20, x19, [sp, #0xc0];
    /* 0x5c2770 */ add x29, sp, #0x70;
    /* 0x5c2774 */ mrs x26, tpidr_el0;
    /* 0x5c2778 */ mov x20, x0;
    /* 0x5c277c */ mov x19, x1;
    /* 0x5c2780 */ ldr x8, [x26, #0x28];
    sub_5a8cfc();
    sub_5a8d04();
    sub_5c9b38();
    sub_5a8d1c();
    sub_5cb124();
    sub_5cb47c();
    sub_dad750();
    sub_dad814();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8d04();
    sub_dad814();
    sub_5c9da4();
    sub_dad750();
    sub_dad7cc();
    sub_5cc228();
    sub_dad7cc();
    sub_5cd5a4();
    sub_5cd634();
    sub_dad814();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5cb124();
    sub_5cb47c();
    sub_daca1c();
    sub_daca8c();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5c9f9c();
    sub_5c9f9c();
    return x0;
    sub_5cc214();
    __stack_chk_fail();
}
