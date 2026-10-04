// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb00cdc
// Recovered Name: sub_b00cdc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb00cdc | Size: 796 bytes | SHA256: 842121870e5bcb7471b2619e2dafa87618df8ef4c10d7e4112eff35680f8b75a
// Callers: 0 | Callees: 16 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "MEITU_HORIZONTAL_GAUSSIAN"
//   "MEITU_VERTICAL_GAUSSIAN"
//   "gaussBlurA"
//   "gaussBlurB"
//   "res/mosaic/mosaic_gaussian.fs"

void sub_b00cdc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 199 instructions
    /* 0xb00cdc */ stp x29, x30, [sp, #0x60];
    /* 0xb00ce0 */ stp x28, x27, [sp, #0x70];
    /* 0xb00ce4 */ stp x26, x25, [sp, #0x80];
    /* 0xb00ce8 */ stp x24, x23, [sp, #0x90];
    /* 0xb00cec */ stp x22, x21, [sp, #0xa0];
    /* 0xb00cf0 */ stp x20, x19, [sp, #0xb0];
    /* 0xb00cf4 */ add x29, sp, #0x60;
    /* 0xb00cf8 */ mrs x28, tpidr_el0;
    /* 0xb00cfc */ mov x19, x0;
    /* 0xb00d00 */ mov x20, x1;
    /* 0xb00d04 */ ldr x8, [x28, #0x28];
    sub_7335b4();
    sub_7440a0();
    sub_7335b4();
    sub_7440a0();
    sub_7335b4();
    sub_7440a0();
    sub_da2fe4();
    sub_da2a38();
    sub_da2fe4();
    sub_da2a40();
    sub_d41edc();
    sub_d421d0();
    sub_d421f4();
    sub_d7ffbc();
    sub_d41edc();
    sub_d41edc();
    sub_d421d0();
    sub_d421f4();
    sub_d7ffbc();
    sub_d41edc();
    sub_d60368();
    sub_d622d8();
    sub_d5b06c();
    sub_d5b06c();
    sub_b00ff8();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    sub_b00ff8();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    return x0;
    sub_da2fe4();
    sub_da2a38();
    sub_da2fe4();
    sub_da2a40();
    __stack_chk_fail();
}
