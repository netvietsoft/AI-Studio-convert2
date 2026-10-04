// Library: libVERenderer.so
// Function ID: libVERenderer::0x382c4
// Recovered Name: sub_382c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x382c4 | Size: 164 bytes | SHA256: 2f4cfcd8d204da4ce1b190d7a4a9b1e39170c6de5f5ca153daf8193b2dd27296
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN10verenderer7Color4FC1ERKNS_7Color3BE, __stack_chk_fail

void sub_382c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x382c4 */ stp x29, x30, [sp, #0x20];
    /* 0x382c8 */ stp x20, x19, [sp, #0x30];
    /* 0x382cc */ add x29, sp, #0x20;
    /* 0x382d0 */ mrs x20, tpidr_el0;
    /* 0x382d4 */ fmov s0, #1.00000000;
    /* 0x382d8 */ ldr x8, [x20, #0x28];
    /* 0x382dc */ stur x8, [x29, #-8];
    /* 0x382e0 */ ldr s1, [x1, #0xc];
    /* 0x382e4 */ fcmp s1, s0;
    /* 0x382e8 */ b.ne #0x38340;
    /* 0x382ec */ mov x19, x1;
    _ZN10verenderer7Color4FC1ERKNS_7Color3BE();
    return x0;
    __stack_chk_fail();
}
